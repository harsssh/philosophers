/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:43:38 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 00:21:42 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"
#include <stdlib.h>

void	destroy_shared_data(t_shared_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->config->num_philos)
		pthread_mutex_destroy(&data->forks[i++]);
	free(data->forks);
	pthread_mutex_destroy(&data->log_lock);
	pthread_mutex_destroy(&data->terminate_lock);
	free(data->config);
}

void	destroy_wisdoms(t_wisdom *wisdoms)
{
	unsigned int	i;

	i = 0;
	while (i < wisdoms->data->config->num_philos)
	{
		pthread_mutex_destroy(&wisdoms[i].last_eat_lock);
		pthread_mutex_destroy(&wisdoms[i].eat_count_lock);
		++i;
	}
	destroy_shared_data(wisdoms->data);
	free(wisdoms);
}
