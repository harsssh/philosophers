/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:19:58 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/05 10:22:24 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

#include <stdint.h>
#include <sys/time.h>

void	safe_free(void **ptr);
int64_t difftimeval(struct timeval t1, struct timeval t2);

#endif
