/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:57:30 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/10 18:57:31 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_ceil(double x)
{
	double	truncated;

	truncated = (double)(long)x;
	if (x > truncated)
		return (truncated + 1.0);
	return (truncated);
}

unsigned int	ft_max(unsigned int a, unsigned int b)
{
	if (a < b)
		return (b);
	return (a);
}
