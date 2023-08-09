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

struct timeval timeval_add_ms(struct timeval t, int msec)
{
	t.tv_usec += (msec % MSEC_IN_SEC) * USEC_IN_MSEC;
	t.tv_sec += msec / MSEC_IN_SEC + t.tv_usec / USEC_IN_SEC;
	t.tv_usec %= USEC_IN_SEC;
	return (t);
}

void	precise_msleep(unsigned int msec)
{
	struct timeval	start;
	struct timeval	end;
	struct timeval	now;
	suseconds_t 	diff;

	gettimeofday(&start, NULL);
	end = timeval_add_ms(start, (int)msec);
	diff = difftimeval_us(start, end);
	while (diff > 0)
	{
		usleep(diff / 2);
		gettimeofday(&now, NULL);
		diff = difftimeval_us(now, end);
	}
}
