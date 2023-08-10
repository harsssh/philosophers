/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:40:48 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/10 18:56:54 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"
#include "util/util.h"
#include <stdint.h>
#include <stdio.h>

static unsigned int	get_timestamp(t_wisdom *wisdom, struct timeval *dest,
		pthread_mutex_t *dest_lock)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	if (dest != NULL)
	{
		if (dest_lock != NULL)
			pthread_mutex_lock(dest_lock);
		*dest = now;
		if (dest_lock != NULL)
			pthread_mutex_unlock(dest_lock);
	}
	return (difftimeval_ms(wisdom->data->start_time, now));
}

void	print_log(t_wisdom *wisdom, const char *format, struct timeval *dest,
		pthread_mutex_t *dest_lock)
{
	unsigned int	timestamp;

	pthread_mutex_lock(&wisdom->data->lock);
	if (wisdom->data->terminate)
	{
		pthread_mutex_unlock(&wisdom->data->lock);
		return ;
	}
	timestamp = get_timestamp(wisdom, dest, dest_lock);
	printf(format, timestamp, wisdom->id);
	pthread_mutex_unlock(&wisdom->data->lock);
}
