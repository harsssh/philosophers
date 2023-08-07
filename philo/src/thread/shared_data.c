/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 00:21:57 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 00:21:58 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	mutex_init(t_shared_data *data)
{
	if (pthread_mutex_init(&data->log_lock, NULL))
		return (-1);
	if (pthread_mutex_init(&data->terminate_lock, NULL))
	{
		pthread_mutex_destroy(&data->log_lock);
		return (-1);
	}
	return (0);
}

t_shared_data	*create_shared_data(t_philo_config *config)
{
	t_shared_data	*data;

	data = malloc(sizeof(t_shared_data));
	if (data == NULL)
		return (NULL);
	data->forks = create_forks(config);
	if (data->forks == NULL)
	{
		free(data);
		return (NULL);
	}
	if (mutex_init(data))
	{
		free(data->forks);
		free(data);
		return (NULL);
	}
	data->config = config;
	data->terminate = false;
	gettimeofday(&data->start_time, NULL);
	return (data);
}
