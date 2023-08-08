/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:59:12 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/05 11:09:23 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "minilibft/minilibft.h"
#include <unistd.h>

# define RED_COLOR "\x1B[31m"
# define RESET_COLOR "\x1B[0m"

void	print_error(const char *message)
{
	size_t	len;

	len = ft_strlen(message);
	write(STDERR_FILENO, message, len);
}

void	print_colored_error(const char *message)
{
	write(STDERR_FILENO, RED_COLOR, sizeof(RED_COLOR) - 1);
	print_error(message);
	write(STDERR_FILENO, RESET_COLOR, sizeof(RESET_COLOR) - 1);
}
