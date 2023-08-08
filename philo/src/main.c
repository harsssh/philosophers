/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 08:55:46 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 22:41:11 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args/args.h"
#include "thread/thread.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_philo_config	config;
	t_dinner		dinner;

	if (parse_args(&config, argc, argv) == PARSE_ERROR)
		return (EXIT_FAILURE);
	if (start_dinner(&dinner, config) == INIT_FAILURE)
		return (EXIT_FAILURE);
	monitor_threads(dinner.wisdoms);
	wait_dinner_end(dinner, config.num_philos);
	return (EXIT_SUCCESS);
}
