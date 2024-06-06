/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_funcs1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:10:45 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/06 16:14:35 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vec_push(t_vec *dst, void *src)
{
	if (dst == NULL || src == NULL)
		return (-1);
	else if (dst->memory == NULL)
		if (vec_new(dst, 1, dst->elem_size) < 0)
			return (-1);
	if (dst->elem_size * dst->len >= dst->alloc_size)
		if (vec_resize(dst, dst->len * 2) < 0)
			return (-1);
	ft_memmove(&dst->memory[dst->len * dst->elem_size], src, dst->elem_size);
	dst->len++;
	return (1);
}
