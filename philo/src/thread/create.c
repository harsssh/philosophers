/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:04:03 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/05 19:40:00 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args/args.h"
#include "thread.h"
#include "util/util.h"
#include <pthread.h>
#include <stdlib.h>

static pthread_mutex_t *create_forks(t_philo_config *config)
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

int 	init_shared_data(t_shared_data *data, t_philo_config *config)
{
	data->forks = create_forks(config);
	if (!data->forks)
		return (-1);
	if (pthread_mutex_init(&data->log_lock, NULL))
	{
		free(data->forks);
		return (-1);
	}
	data->config = config;
	gettimeofday(&data->start_time, NULL);
	return (0);
}

static t_wisdom *create_wisdoms(t_shared_data *data)
{
	t_wisdom *wisdoms;
	unsigned int i;

	wisdoms = malloc(sizeof(t_wisdom) * data->config->num_philos);
	if (wisdoms == NULL)
		return (NULL);
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


pthread_t	*create_threads(t_shared_data *data)
{
	t_wisdom *all_wisdom;
	pthread_t *philos;
	unsigned int i;

	all_wisdom = create_wisdoms(data);
	if (all_wisdom == NULL)
		return (NULL);
	philos = malloc(sizeof(pthread_t) * data->config->num_philos);
	if (philos == NULL)
	{
		free(all_wisdom);
		return (NULL);
	}
	i = 0;
	while (i < data->config->num_philos)
		;
}