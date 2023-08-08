/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:42:23 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 15:01:53 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "thread.h"
#include "util/util.h"

static void	choose_forks(t_wisdom *wisdom, pthread_mutex_t **first_fork,
		pthread_mutex_t **second_fork)
{
	*first_fork = wisdom->data->forks + (wisdom->id - 1);
	*second_fork = wisdom->data->forks + wisdom->id
		% wisdom->data->config.num_philos;
	if (wisdom->id == 1)
		swap_pointer((void **)first_fork, (void **)second_fork);
}

static void	take_fork(t_wisdom *wisdom, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	print_log(wisdom, MSG_TAKE_FORK);
}

static void	philo_eat(t_wisdom *wisdom)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	choose_forks(wisdom, &first_fork, &second_fork);
	take_fork(wisdom, first_fork);
	if (wisdom->data->config.num_philos == 1)
	{
		pthread_mutex_unlock(second_fork);
		msleep(wisdom->data->config.die_time * 2);
		return ;
	}
	take_fork(wisdom, second_fork);
	safe_increment_uint(&wisdom->eat_count, &wisdom->eat_count_lock);
	safe_update_timeval(&wisdom->last_eat, &wisdom->last_eat_lock);
	print_log(wisdom, MSG_EAT);
	msleep(wisdom->data->config.eat_time);
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
}

static void	philo_sleep(t_wisdom *wisdom)
{
	print_log(wisdom, MSG_SLEEP);
	msleep(wisdom->data->config.sleep_time);
}

void	*philo_routine(void *arg)
{
	t_wisdom		*wisdom;
	t_shared_data	*data;

	wisdom = (t_wisdom *)arg;
	data = wisdom->data;
	while (!safe_read_bool(&data->terminate, &data->terminate_lock))
	{
		print_log(wisdom, MSG_THINK);
		philo_eat(wisdom);
		philo_sleep(wisdom);
	}
	return (NULL);
}
