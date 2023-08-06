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

typedef struct s_philo_config
{
	unsigned int	num_philosophers;
	unsigned int	die_time;
	unsigned int	eat_time;
	unsigned int	sleep_time;
	unsigned int	min_eat_count;
	bool			has_optional_arg;
}					t_philo_config;

t_philo_config		*parse_args(int argc, char **argv);

#endif
