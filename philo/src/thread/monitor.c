/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:15:31 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/07 23:15:32 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "thread.h"
#include "util/util.h"
#include <unistd.h>

#define DELAY 5000

void	monitor_threads(t_wisdom *wisdoms)
{
	struct timeval	now;
	unsigned int	die_time;
	unsigned int	i;

	die_time = wisdoms->data->config->die_time;
	while (true)
	{
		i = 0;
		while (i < wisdoms->data->config->num_philos)
		{
			gettimeofday(&now, NULL);
			pthread_mutex_lock(&wisdoms[i].last_eat_lock);
			if (difftimeval(wisdoms[i].last_eat, now) >= die_time)
			{
				print_log(wisdoms + i, MSG_DIE);
				pthread_mutex_lock(&wisdoms->data->terminate_lock);
				wisdoms->data->terminate = true;
				pthread_mutex_unlock(&wisdoms->data->terminate_lock);
				return ;
			}
			pthread_mutex_unlock(&wisdoms[i].last_eat_lock);
			++i;
		}
		usleep(DELAY);
	}
}
