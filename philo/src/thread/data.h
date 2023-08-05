/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:55:39 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/05 21:52:55 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "args/args.h"
# include "entity/philosopher.h"
# include <pthread.h>
# include <sys/time.h>

typedef struct s_shared_data
{
	t_philo_args	args;
	t_philo			*philo;
	pthread_mutex_t	log_lock;
	struct timeval	start_time;
}					t_shared_data;

#endif
