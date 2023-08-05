/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:56:54 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/05 10:53:05 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include "stdbool.h"

typedef struct s_philo_args
{
	unsigned long	num_philosophers;
	unsigned long	die_time;
	unsigned long	eat_time;
	unsigned long	sleep_time;
	unsigned long	min_eat_count;
	bool			has_optional_arg;
}					t_philo_args;

t_philo_args		*parse_args(int argc, char **argv);

#endif
