/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:40:48 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/07 16:40:49 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>

static int64_t	get_timestamp(t_wisdom *wisdom)
{
	struct timeval	now;
	int64_t			sec;
	int64_t			usec;

	gettimeofday(&now, NULL);
	sec = now.tv_sec - wisdom->data->start_time.tv_sec;
	usec = now.tv_usec - wisdom->data->start_time.tv_usec;
	return (sec * 1000 + usec / 1000);
}

void	print_log(t_wisdom *wisdom, const char *format)
{
	int64_t	timestamp;

	pthread_mutex_lock(&wisdom->data->log_lock);
	timestamp = get_timestamp(wisdom);
	printf(format, timestamp, wisdom->id);
	pthread_mutex_unlock(&wisdom->data->log_lock);
}
