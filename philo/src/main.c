/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 08:55:46 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/07 14:43:18 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args/args.h"
#include "error/error.h"
#include "thread/thread.h"
#include <pthread.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

static t_wisdom	*create_thread_data(int argc, char **argv)
{
	t_philo_config	*config;
	t_wisdom		*wisdoms;

	config = parse_args(argc, argv);
	if (config == NULL)
	{
		print_error(USAGE);
		return (NULL);
	}
	wisdoms = create_wisdoms(config);
	if (wisdoms == NULL)
	{
		free(config);
		return (NULL);
	}
	return (wisdoms);
}

int	main(int argc, char **argv)
{
	t_wisdom	*wisdoms;
	pthread_t	*philos;

	wisdoms = create_thread_data(argc, argv);
	if (wisdoms == NULL)
		return (EXIT_FAILURE);
	philos = create_threads(wisdoms);
	if (philos == NULL)
	{
		destroy_wisdoms(wisdoms);
		return (EXIT_FAILURE);
	}
	monitor_threads(wisdoms);
	wait_threads(philos, wisdoms->data->config->num_philos);
	destroy_wisdoms(wisdoms);
	return (EXIT_SUCCESS);
}
