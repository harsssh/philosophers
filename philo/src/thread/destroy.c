/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:43:38 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 15:21:41 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "thread.h"
#include <stdlib.h>

void	destroy_wisdoms(t_wisdom *wisdoms)
{
	unsigned int	i;

	i = 0;
	while (i < wisdoms->data->config.num_philos)
	{
		pthread_mutex_destroy(&wisdoms[i].last_eat_lock);
		pthread_mutex_destroy(&wisdoms[i].eat_count_lock);
		++i;
	}
	destroy_shared_data(wisdoms->data);
	free(wisdoms);
}
