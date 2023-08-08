/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:15:31 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 00:21:49 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"
#include "util/util.h"
#include <unistd.h>

#define DELAY 1000

static bool	is_satisfied(t_wisdom *wisdom);
static bool	is_dead(t_wisdom *wisdom);
static void	notify_termination(t_shared_data *data);
static int	monitor_each_thread(t_wisdom *wisdoms, unsigned int *satisfied_philos);

void	monitor_threads(t_wisdom *wisdoms)
{
	t_philo_config	config;
	unsigned int	satisfied_philos;

	config = wisdoms->data->config;
	while (true)
	{
		satisfied_philos = 0;
		if (monitor_each_thread(wisdoms, &satisfied_philos))
			return ;
		if (config.has_optional_arg && satisfied_philos == config.num_philos)
		{
			notify_termination(wisdoms->data);
			return ;
		}
		usleep(DELAY);
	}
}

static bool	is_satisfied(t_wisdom *wisdom)
{
	bool	satisfied;

	pthread_mutex_lock(&wisdom->lock);
	satisfied = wisdom->eat_count >= wisdom->data->config.min_eat_count;
	pthread_mutex_unlock(&wisdom->lock);
	return (satisfied);
}

static bool	is_dead(t_wisdom *wisdom)
{
	struct timeval	now;
	bool			dead;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(&wisdom->lock);
	dead = difftimeval(wisdom->last_eat, now) >= wisdom->data->config.die_time;
	pthread_mutex_unlock(&wisdom->lock);
	return (dead);
}

static void	notify_termination(t_shared_data *data)
{
	pthread_mutex_lock(&data->lock);
	data->terminate = true;
	pthread_mutex_unlock(&data->lock);
}

static int	monitor_each_thread(t_wisdom *wisdoms,
		unsigned int *satisfied_philos)
{
	unsigned int	i;

	i = 0;
	while (i < wisdoms->data->config.num_philos)
	{
		if (is_satisfied(wisdoms + i))
			++(*satisfied_philos);
		if (is_dead(wisdoms + i))
		{
			print_log(wisdoms + i, MSG_DIE);
			notify_termination(wisdoms->data);
			return (-1);
		}
		++i;
	}
	return (0);
}