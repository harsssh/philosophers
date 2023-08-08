/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:41:21 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/08 22:41:24 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H

# include <stddef.h>

int		ft_isspace(int c);
int		ft_isdigit(int c);
long	ft_atol(const char *str);
size_t	ft_strlen(const char *s);

#endif
