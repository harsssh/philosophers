/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:19:58 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 15:39:45 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <pthread.h>
# include <stdint.h>
# include <sys/time.h>

# define USEC_IN_MSEC 	1000
# define MSEC_IN_SEC 	1000
# define USEC_IN_SEC 	1000000

// math.c
double 			ft_ceil(double x);
unsigned int 	ft_max(unsigned int a, unsigned int b);

// swap.c
void			swap_pointer(void **a, void **b);

// time.c
int 			difftimeval_ms(struct timeval t1, struct timeval t2);
suseconds_t 	difftimeval_us(struct timeval t1, struct timeval t2);
struct timeval 	timeval_add_ms(struct timeval t, int msec);
void			precise_msleep_until(struct timeval end);
void			precise_msleep(unsigned int msec);

// safe_rw.c
bool			safe_read_bool(const bool *ptr, pthread_mutex_t *lock);
unsigned int	safe_read_uint(const unsigned int *ptr, pthread_mutex_t *lock);
void			safe_increment_uint(unsigned int *ptr, pthread_mutex_t *lock);
void			safe_update_timeval(struct timeval *ptr, pthread_mutex_t *lock);

#endif
