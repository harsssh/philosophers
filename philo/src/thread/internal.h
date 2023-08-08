/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:43:44 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 15:01:01 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "thread.h"

# define MSG_TAKE_FORK	"%llu %u has taken a fork\n"
# define MSG_EAT		"%llu %u is eating\n"
# define MSG_SLEEP		"%llu %u is sleeping\n"
# define MSG_THINK		"%llu %u is thinking\n"
# define MSG_DIE		"%llu %u died\n"

t_shared_data	*create_shared_data(t_philo_config *config);
void			destroy_shared_data(t_shared_data *data);
void			print_log(t_wisdom *wisdom, const char *format);

#endif
