/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:22:21 by kemizuki          #+#    #+#             */
/*   Updated: 2023/08/05 10:22:21 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	safe_free(void **ptr)
{
	if (!(ptr == NULL || *ptr == NULL))
	{
		free(*ptr);
		*ptr = NULL;
	}
}