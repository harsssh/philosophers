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
#include <stdlib.h>
#include "thread.h"

void	wait_dinner_end(t_dinner dinner, unsigned int num_philos)
{
	unsigned int	i;

	i = 0;
	while (i < num_philos)
		pthread_join(dinner.philos[i++], NULL);
	free(dinner.philos);
	destroy_wisdoms(dinner.wisdoms);
}
