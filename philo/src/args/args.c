/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:15:07 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 11:29:17 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "error/error.h"
#include "minilibft/minilibft.h"
#include <errno.h>
#include <limits.h>
#include <stdbool.h>

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

static void	init_set_config(t_philo_config *args, int argc,
		unsigned int *dest[5])
{
	dest[0] = &args->num_philos;
	dest[1] = &args->die_time;
	dest[2] = &args->eat_time;
	dest[3] = &args->sleep_time;
	args->has_optional_arg = false;
	if (argc == 6)
	{
		dest[4] = &args->min_eat_count;
		args->has_optional_arg = true;
	}
}

static int	set_config(t_philo_config *args, int argc, char **argv)
{
	unsigned int	*dest[5];
	unsigned int	i;

	init_set_config(args, argc, dest);
	i = 0;
	while (i < (unsigned int)argc - 1)
	{
		*dest[i] = ft_atol(argv[i + 1]);
		if (errno == ERANGE || *dest[i] > UINT_MAX)
		{
			print_colored_error(E_TOO_LARGE_ARG);
			return (PARSE_ERROR);
		}
		else if (*dest[i] == 0)
		{
			print_colored_error(E_ZERO_ARG);
			return (PARSE_ERROR);
		}
		++i;
	}
	return (PARSE_SUCCESS);
}

int parse_args(t_philo_config *config, int argc, char **argv)
{
	if (!is_valid_args(argc, argv) || set_config(config, argc, argv) == PARSE_ERROR)
	{
		print_error(USAGE);
		return (PARSE_ERROR);
	}
	return (PARSE_SUCCESS);
}
