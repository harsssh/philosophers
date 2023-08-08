/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:04:03 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 00:21:25 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args/args.h"
#include "internal.h"
#include "thread.h"
#include <pthread.h>
#include <stdlib.h>

static int	init_wisdoms(t_wisdom *wisdoms, t_shared_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->config.num_philos)
	{
		if (pthread_mutex_init(&wisdoms[i].lock, NULL))
		{
			while (i--)
				pthread_mutex_destroy(&wisdoms[i].lock);
			return (-1);
		}
		wisdoms[i].id = i + 1;
		wisdoms[i].eat_count = 0;
		wisdoms[i].last_eat = data->start_time;
		wisdoms[i].data = data;
		++i;
	}
	return (0);
}

t_wisdom	*create_wisdoms(t_philo_config config)
{
	t_shared_data	*data;
	t_wisdom		*wisdoms;

	data = create_shared_data(config);
	if (data == NULL)
		return (NULL);
	wisdoms = malloc(sizeof(t_wisdom) * data->config.num_philos);
	if (wisdoms == NULL)
	{
		destroy_shared_data(data);
		return (NULL);
	}
	if (init_wisdoms(wisdoms, data))
	{
		destroy_wisdoms(wisdoms);
		return (NULL);
	}
	return (wisdoms);
}

pthread_t	*create_threads(t_wisdom *wisdoms)
{
	pthread_t		*philos;
	unsigned int	i;

	philos = malloc(sizeof(pthread_t) * wisdoms->data->config.num_philos);
	if (philos == NULL)
		return (NULL);
	i = 0;
	while (i < wisdoms->data->config.num_philos)
	{
		if (pthread_create(philos + i, NULL, philo_routine, wisdoms + i))
		{
			pthread_mutex_lock(&wisdoms->data->terminate_lock);
			wisdoms->data->terminate = true;
			pthread_mutex_unlock(&wisdoms->data->terminate_lock);
			free(philos);
			return (NULL);
		}
		++i;
	}
	return (philos);
}
