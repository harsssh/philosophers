/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_rw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:01:59 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 15:02:00 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

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
