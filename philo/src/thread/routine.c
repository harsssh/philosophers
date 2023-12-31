/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:42:23 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/10 18:55:18 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	print_log(wisdom, MSG_TAKE_FORK, NULL, NULL);
}

static void	philo_eat(t_wisdom *wisdom)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	precise_msleep_until(wisdom->next_eat);
	choose_forks(wisdom, &first_fork, &second_fork);
	take_fork(wisdom, first_fork);
	if (wisdom->data->config.num_philos == 1)
	{
		pthread_mutex_unlock(second_fork);
		precise_msleep(wisdom->data->config.die_time * 2);
		return ;
	}
	take_fork(wisdom, second_fork);
	safe_increment_uint(&wisdom->eat_count, &wisdom->lock);
	print_log(wisdom, MSG_EAT, &wisdom->last_eat, &wisdom->lock);
	precise_msleep(wisdom->data->config.eat_time);
	wisdom->next_eat = timeval_add_ms(wisdom->last_eat,
			wisdom->data->eat_interval);
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
}

static void	philo_sleep(t_wisdom *wisdom)
{
	print_log(wisdom, MSG_SLEEP, NULL, NULL);
	precise_msleep(wisdom->data->config.sleep_time);
}

void	*philo_routine(void *arg)
{
	t_wisdom		*wisdom;
	t_shared_data	*data;

	wisdom = (t_wisdom *)arg;
	data = wisdom->data;
	precise_msleep_until(data->start_time);
	while (!safe_read_bool(&data->terminate, &data->lock))
	{
		print_log(wisdom, MSG_THINK, NULL, NULL);
		philo_eat(wisdom);
		philo_sleep(wisdom);
	}
	return (NULL);
}
