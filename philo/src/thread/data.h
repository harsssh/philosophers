/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:55:39 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/05 18:55:39 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "args/args.h"
# include "entity/philosopher.h"
# include <pthread.h>

typedef struct s_shared_data
{
	t_philo_args	args;
	t_philo			*philos;
	pthread_mutex_t	log_lock;
}					t_shared_data;

#endif
