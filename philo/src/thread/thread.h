/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:56:16 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 00:21:16 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include "args/args.h"
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_shared_data
{
	pthread_mutex_t lock;
	t_philo_config	config;
	pthread_mutex_t	*forks;
	bool			terminate;
	struct timeval	start_time;
}					t_shared_data;

typedef struct s_wisdom
{
	pthread_mutex_t lock;
	unsigned int	id;
	struct timeval	last_eat;
	unsigned int	eat_count;
	t_shared_data	*data;
}					t_wisdom;

t_wisdom			*create_wisdoms(t_philo_config config);
pthread_t			*create_threads(t_wisdom *wisdoms);

void				destroy_wisdoms(t_wisdom *wisdoms);

void				*philo_routine(void *arg);
void				monitor_threads(t_wisdom *wisdoms);
void				wait_threads(pthread_t *philos, unsigned int num_philos);

#endif
