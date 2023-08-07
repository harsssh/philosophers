/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 00:20:40 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 00:20:42 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

void	wait_threads(pthread_t *philos, unsigned int num_philos)
{
	unsigned int	i;

	i = 0;
	while (i < num_philos)
		pthread_join(philos[i++], NULL);
}
