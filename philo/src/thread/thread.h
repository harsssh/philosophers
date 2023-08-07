/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:56:16 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/05 18:56:17 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include "args/args.h"
# include <sys/time.h>
#include <pthread.h>

typedef struct s_shared_data
{
	t_philo_config	*config;
	pthread_mutex_t *forks;
	pthread_mutex_t	log_lock;
	struct timeval	start_time;
} t_shared_data;

typedef struct s_wisdom
{
	unsigned int	id;
	struct timeval	last_eat;
	unsigned int	eat_count;
	t_shared_data 	*data;
}					t_wisdom;

pthread_t	*create_threads(t_shared_data *data);
int 	init_shared_data(t_shared_data *data, t_philo_config *config);

#endif
