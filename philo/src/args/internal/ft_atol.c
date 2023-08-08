/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:47:22 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/05 09:39:38 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args/internal.h"
#include <errno.h>
#include <limits.h>

static int	read_up_to_sign(const char **s)
{
	while (**s && ft_isspace(**s))
		(*s)++;
	if (**s && **s == '-')
	{
		(*s)++;
		return (-1);
	}
	if (**s && **s == '+')
		(*s)++;
	return (1);
}

// whether sign * (num * 10 + x) overflows the range for longs
static int	is_overflow(int sign, unsigned long num, unsigned long x)
{
	unsigned long	limit;

	if (sign == 1)
		limit = LONG_MAX;
	else
		limit = -LONG_MIN;
	return (limit / 10 < num || limit - num * 10 < x);
}

long	ft_atol(const char *str)
{
	int				sign;
	unsigned long	num;
	unsigned long	x;

	num = 0;
	sign = read_up_to_sign(&str);
	while (*str && ft_isdigit(*str))
	{
		x = *str++ - '0';
		if (is_overflow(sign, num, x))
		{
			errno = ERANGE;
			if (sign > 0)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		num = num * 10 + x;
	}
	return (sign * num);
}
