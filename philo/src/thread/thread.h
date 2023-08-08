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
	t_philo_config	config;
	pthread_mutex_t	*forks;
	pthread_mutex_t	log_lock;
	bool			terminate;
	pthread_mutex_t	terminate_lock;
	struct timeval	start_time;
}					t_shared_data;

typedef struct s_wisdom
{
	unsigned int	id;
	struct timeval	last_eat;
	pthread_mutex_t	last_eat_lock;
	unsigned int	eat_count;
	pthread_mutex_t	eat_count_lock;
	t_shared_data	*data;
}					t_wisdom;

t_wisdom			*create_wisdoms(t_philo_config config);
pthread_t			*create_threads(t_wisdom *wisdoms);

void				destroy_wisdoms(t_wisdom *wisdoms);

void				*philo_routine(void *arg);
void				monitor_threads(t_wisdom *wisdoms);
void				wait_threads(pthread_t *philos, unsigned int num_philos);

#endif
