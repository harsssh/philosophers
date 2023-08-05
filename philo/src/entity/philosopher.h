/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:56:16 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/05 18:56:17 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "fork.h"
# include <sys/time.h>

typedef struct s_philo
{
	unsigned int	id;
	struct timeval	last_eat;
	unsigned int	eat_count;
	t_fork			*left_fork;
	t_fork			*right_fork;
}					t_philo;

#endif
