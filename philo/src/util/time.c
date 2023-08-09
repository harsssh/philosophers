/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 00:22:10 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 12:15:29 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>

# define USEC_IN_MSEC 	1000
# define MSEC_IN_SEC 	1000
# define USEC_IN_SEC 	1000000

int difftimeval_ms(struct timeval t1, struct timeval t2)
{
	int diff;

	diff = (suseconds_t)(t2.tv_sec - t1.tv_sec) * MSEC_IN_SEC;
	diff += (t2.tv_usec - t1.tv_usec) / USEC_IN_MSEC;
	return (diff);
}

suseconds_t difftimeval_us(struct timeval t1, struct timeval t2)
{
	suseconds_t diff;

	diff = (suseconds_t)(t2.tv_sec - t1.tv_sec) * USEC_IN_SEC;
	diff += t2.tv_usec - t1.tv_usec;
	return (diff);
}

void	msleep(unsigned int msec)
{
	usleep(msec * USEC_IN_MSEC);
}
