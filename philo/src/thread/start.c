/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:04:03 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 22:39:53 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args/args.h"
#include "thread.h"
#include <pthread.h>
#include <stdlib.h>

static pthread_mutex_t	*create_forks(t_philo_config config);
static t_shared_data	*create_shared_data(t_philo_config config);
static int				init_wisdoms(t_wisdom *wisdoms, t_shared_data *data);
static t_wisdom			*create_wisdoms(t_philo_config config);

int	start_dinner(t_dinner *dinner, t_philo_config config)
{
	unsigned int	i;
	t_shared_data	*data;

	dinner->wisdoms = create_wisdoms(config);
	if (dinner->wisdoms == NULL)
		return (INIT_FAILURE);
	dinner->philos = malloc(sizeof(pthread_t) * config.num_philos);
	if (dinner->philos == NULL)
	{
		destroy_wisdoms(dinner->wisdoms);
		return (INIT_FAILURE);
	}
	i = 0;
	data = dinner->wisdoms->data;
	while (i < config.num_philos)
	{
		if (pthread_create(dinner->philos + i, NULL, philo_routine,
				dinner->wisdoms + i))
		{
			pthread_mutex_lock(&data->lock);
			data->terminate = true;
			pthread_mutex_unlock(&data->lock);
			wait_dinner_end(*dinner, i);
			return (INIT_FAILURE);
		}
		++i;
	}
	return (INIT_SUCCESS);
}

static pthread_mutex_t	*create_forks(t_philo_config config)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * config.num_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < config.num_philos)
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

static t_shared_data	*create_shared_data(t_philo_config config)
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
	if (pthread_mutex_init(&data->lock, NULL))
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
			return (INIT_FAILURE);
		}
		wisdoms[i].id = i + 1;
		wisdoms[i].eat_count = 0;
		wisdoms[i].last_eat = data->start_time;
		wisdoms[i].data = data;
		++i;
	}
	return (INIT_SUCCESS);
}

static t_wisdom	*create_wisdoms(t_philo_config config)
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
