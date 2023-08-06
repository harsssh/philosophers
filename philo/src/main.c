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
#include "stddef.h"
#include "error/error.h"
#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int	main(int argc, char **argv)
{
	t_philo_config	*config;

	config = parse_args(argc, argv);
	if (config == NULL)
	{
		print_error(USAGE);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
