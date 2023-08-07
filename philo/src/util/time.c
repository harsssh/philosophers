/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 00:22:10 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 00:22:11 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

int64_t	difftimeval(struct timeval t1, struct timeval t2)
{
	int64_t	sec;
	int64_t	usec;

	sec = t2.tv_sec - t1.tv_sec;
	usec = t2.tv_usec - t1.tv_usec;
	return (sec * 1000 + usec / 1000);
}

int64_t	difftimeval_us(struct timeval t1, struct timeval t2)
{
	int64_t	sec;
	int64_t	usec;

	sec = t2.tv_sec - t1.tv_sec;
	usec = t2.tv_usec - t1.tv_usec;
	return (sec * 1000000 + usec);
}
