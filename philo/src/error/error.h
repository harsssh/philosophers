/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:55:49 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 00:48:39 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define USAGE "Usage: philo \
number_of_philosophers \
time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n"

# define E_NON_NUMERIC_ARG	"Error: non-numeric argument\n"
# define E_TOO_LARGE_ARG	"Error: too large argument\n"
# define E_ZERO_ARG			"Error: each argument must be positive\n"


void	print_error(const char *message);
void	print_colored_error(const char *message);

#endif
