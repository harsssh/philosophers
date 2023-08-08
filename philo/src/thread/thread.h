/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:56:16 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 22:41:02 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include "args/args.h"
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

# define MSG_TAKE_FORK	"%llu %u has taken a fork\n"
# define MSG_EAT		"%llu %u is eating\n"
# define MSG_SLEEP		"%llu %u is sleeping\n"
# define MSG_THINK		"%llu %u is thinking\n"
# define MSG_DIE		"%llu %u died\n"

# define INIT_FAILURE -1
# define INIT_SUCCESS 0

typedef struct s_shared_data
{
	pthread_mutex_t	lock;
	t_philo_config	config;
	pthread_mutex_t	*forks;
	bool			terminate;
	struct timeval	start_time;
}					t_shared_data;

typedef struct s_wisdom
{
	pthread_mutex_t	lock;
	unsigned int	id;
	struct timeval	last_eat;
	unsigned int	eat_count;
	t_shared_data	*data;
}					t_wisdom;

typedef struct s_dinner
{
	pthread_t		*philos;
	t_wisdom		*wisdoms;
}					t_dinner;

// destroy.c
void	destroy_wisdoms(t_wisdom *wisdoms);
void	destroy_shared_data(t_shared_data *data);

// start.c
int		start_dinner(t_dinner *dinner, t_philo_config config);

// log.c
void	print_log(t_wisdom *wisdom, const char *format);

// routine.c
void	*philo_routine(void *arg);

// monitor.c
void	monitor_threads(t_wisdom *wisdoms);

// wait.c
void	wait_dinner_end(t_dinner dinner, unsigned int num_philos);

#endif
