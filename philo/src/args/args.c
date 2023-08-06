/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:15:07 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/05 18:56:00 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "error/error.h"
#include "internal.h"
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

static bool	is_valid_number(const char *s)
{
	if (s == NULL || *s == '\0')
		return (false);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		++s;
	}
	return (true);
}

static bool	is_valid_args(int argc, char **argv)
{
	unsigned int	i;

	if (!(argc == 5 || argc == 6))
		return (false);
	i = 1;
	while (i < (unsigned int)argc)
	{
		if (!is_valid_number(argv[i]))
		{
			print_colored_error(E_NON_NUMERIC_ARG);
			return (false);
		}
		++i;
	}
	return (true);
}

static int	set_args(t_philo_config *args, int argc, char **argv)
{
	unsigned int	*dest[5];
	unsigned int	i;

	dest[0] = &args->num_philosophers;
	dest[1] = &args->die_time;
	dest[2] = &args->eat_time;
	dest[3] = &args->sleep_time;
	args->has_optional_arg = false;
	if (argc == 6)
	{
		dest[4] = &args->min_eat_count;
		args->has_optional_arg = true;
	}
	i = 0;
	while (i < (unsigned int)argc - 1)
	{
		*dest[i] = ft_atol(argv[i + 1]);
		if (errno == ERANGE || *dest[i] > UINT_MAX)
		{
			print_colored_error(E_TOO_LARGE_ARG);
			return (-1);
		}
		++i;
	}
	return (0);
}

t_philo_config	*parse_args(int argc, char **argv)
{
	t_philo_config	*args;

	args = malloc(sizeof(t_philo_config));
	if (args == NULL)
		return (NULL);
	if (!is_valid_args(argc, argv))
	{
		free(args);
		return (NULL);
	}
	if (set_args(args, argc, argv) == -1)
	{
		free(args);
		return (NULL);
	}
	return (args);
}
