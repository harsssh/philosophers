/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_rw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:01:59 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 15:39:54 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>
#include <sys/time.h>

bool	safe_read_bool(const bool *ptr, pthread_mutex_t *lock)
{
	bool	ret;

	pthread_mutex_lock(lock);
	ret = *ptr;
	pthread_mutex_unlock(lock);
	return (ret);
}

unsigned int	safe_read_uint(const unsigned int *ptr, pthread_mutex_t *lock)
{
	unsigned int	ret;

	pthread_mutex_lock(lock);
	ret = *ptr;
	pthread_mutex_unlock(lock);
	return (ret);
}

void	safe_increment_uint(unsigned int *ptr, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	++(*ptr);
	pthread_mutex_unlock(lock);
}

void	safe_update_timeval(struct timeval *ptr, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	gettimeofday(ptr, NULL);
	pthread_mutex_unlock(lock);
}
