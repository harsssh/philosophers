/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:42:23 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 11:53:07 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "thread.h"
#include "util/util.h"
#include <unistd.h>

static void	philo_think(t_wisdom *wisdom)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	print_log(wisdom, MSG_THINK);
	first_fork = wisdom->data->forks + (wisdom->id - 1);
	second_fork = wisdom->data->forks + wisdom->id
		% wisdom->data->config->num_philos;
	if (wisdom->id & 1)
		swap_pointer((void **)&first_fork, (void **)&second_fork);
	pthread_mutex_lock(second_fork);
	print_log(wisdom, MSG_TAKE_FORK);
	if (wisdom->data->config->num_philos == 1)
	{
		pthread_mutex_unlock(second_fork);
		usleep(wisdom->data->config->die_time * 2 * 1000);
		return ;
	}
	pthread_mutex_lock(first_fork);
	print_log(wisdom, MSG_TAKE_FORK);
}

static void	philo_eat(t_wisdom *wisdom)
{
	pthread_mutex_lock(&wisdom->eat_count_lock);
	++wisdom->eat_count;
	pthread_mutex_unlock(&wisdom->eat_count_lock);
	gettimeofday(&wisdom->last_eat, NULL);
	print_log(wisdom, MSG_EAT);
	usleep(wisdom->data->config->eat_time * 1000);
	pthread_mutex_unlock(wisdom->data->forks + (wisdom->id - 1));
	pthread_mutex_unlock(wisdom->data->forks + wisdom->id
		% wisdom->data->config->num_philos);
}

static void	philo_sleep(t_wisdom *wisdom)
{
	print_log(wisdom, MSG_SLEEP);
	usleep(wisdom->data->config->sleep_time * 1000);
}

void	*philo_routine(void *arg)
{
	t_wisdom	*wisdom;

	wisdom = (t_wisdom *)arg;
	while (true)
	{
		pthread_mutex_lock(&wisdom->data->terminate_lock);
		if (wisdom->data->terminate)
		{
			pthread_mutex_unlock(&wisdom->data->terminate_lock);
			break ;
		}
		pthread_mutex_unlock(&wisdom->data->terminate_lock);
		philo_think(wisdom);
		philo_eat(wisdom);
		philo_sleep(wisdom);
	}
	return (NULL);
}
