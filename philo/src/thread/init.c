/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:04:03 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/05 19:40:00 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args/args.h"
#include <pthread.h>
#include <stdlib.h>

static pthread_t	*init_threads(t_philo_args *args)
{
	pthread_t	*threads;
	unsigned int i;

	threads = malloc(sizeof(t_philo_args) * args->num_philosophers);
	if (threads == NULL)
		return (NULL);
	i = 0;
	while (i < args->num_philosophers)
	{
		threads[i] = ;
	}
}

pthread_t	*prepare_dinner(t_philo_args *args)
{
}
