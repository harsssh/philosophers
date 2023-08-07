/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:04:03 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/07 14:43:54 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args/args.h"
#include "internal.h"
#include "thread.h"
#include <pthread.h>
#include <stdlib.h>

static pthread_mutex_t	*create_forks(t_philo_config *config)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * config->num_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < config->num_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL))
		{
			while (i--)
				pthread_mutex_destroy(&forks[i]);
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

static t_shared_data	*create_shared_data(t_philo_config *config)
{
	t_shared_data	*data;

	data = malloc(sizeof(t_shared_data));
	if (data == NULL)
		return (NULL);
	data->forks = create_forks(config);
	if (!data->forks)
	{
		free(data);
		return (NULL);
	}
	if (pthread_mutex_init(&data->log_lock, NULL))
	{
		free(data->forks);
		free(data);
		return (NULL);
	}
	data->config = config;
	gettimeofday(&data->start_time, NULL);
	return (0);
}

t_wisdom	*create_wisdoms(t_philo_config *config)
{
	t_shared_data	*data;
	t_wisdom		*wisdoms;
	unsigned int	i;

	data = create_shared_data(config);
	if (data == NULL)
		return (NULL);
	wisdoms = malloc(sizeof(t_wisdom) * data->config->num_philos);
	if (wisdoms == NULL)
	{
		destroy_shared_data(data);
		return (NULL);
	}
	i = 0;
	while (i < data->config->num_philos)
	{
		wisdoms[i].id = i + 1;
		wisdoms[i].eat_count = 0;
		wisdoms[i].last_eat = data->start_time;
		wisdoms[i].data = data;
		i++;
	}
	return (wisdoms);
}

pthread_t	*create_threads(t_wisdom *wisdoms)
{
	pthread_t		*philos;
	unsigned int	i;

	philos = malloc(sizeof(pthread_t) * wisdoms->data->config->num_philos);
	if (philos == NULL)
		return (NULL);
	i = 0;
	while (i < wisdoms->data->config->num_philos)
	{
		// TODO: handle error
		pthread_create(philos + i, NULL, philo_routine, wisdoms + i);
	}
	return (philos);
}
