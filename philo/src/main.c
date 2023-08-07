/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 08:55:46 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/05 11:01:20 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args/args.h"
#include "error/error.h"
#include "thread/thread.h"
#include <stdlib.h>
#include <pthread.h>

int	main(int argc, char **argv)
{
	t_philo_config	*config;
	t_shared_data 	data;
	t_wisdom		*wisdoms;
	pthread_t 		*philos;

	config = parse_args(argc, argv);
	if (config == NULL)
	{
		free(config);
		print_error(USAGE);
		return (1);
	}
	if (init_shared_data(&data, config))
	{
		free(config);
		return (1);
	}
	return (0);
}
