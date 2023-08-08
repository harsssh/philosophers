/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:56:54 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/07 14:43:31 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include "stdbool.h"

# define PARSE_ERROR -1
# define PARSE_SUCCESS 0

typedef struct s_philo_config
{
	unsigned int	num_philos;
	unsigned int	die_time;
	unsigned int	eat_time;
	unsigned int	sleep_time;
	unsigned int	min_eat_count;
	bool			has_optional_arg;
}					t_philo_config;

int parse_args(t_philo_config *config, int argc, char **argv);

#endif
