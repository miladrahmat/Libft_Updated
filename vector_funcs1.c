/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_funcs1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:10:45 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/07 16:00:19 by mrahmat-         ###   ########.fr       */
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

int	vec_pop(void *dst, t_vec *src)
{
	if (dst == NULL || src == NULL)
		return (-1);
	ft_memmove(dst, &src->memory[(src->len - 1) * src->elem_size], \
		src->elem_size);
	src->len--;
	return (1);
}

void	*vec_get(t_vec *src, size_t index)
{
	if (src == NULL || src->len <= index)
		return (NULL);
	return (&src->memory[src->elem_size * index]);
}

int	vec_insert(t_vec *dst, void *src, size_t index)
{
	void	temp;

	if (dst == NULL || src == NULL || dst->len <= index)
		return (-1);
	if ((dst->len + 1) * dst->elem_size >= dst->alloc_size)
		if (vec_resize(dst, dst->len + 1) < 0)
			return (-1);
	while (index < dst->len)
	{
		temp = vec_get(dst, index);
		ft_memmove(&dst->memory[dst->elem_size * index], src, dst->elem_size);
		ft_memmove(src, &dst->memory[dst->elem_size * index], dst->elem_size);
		ft_memmove(&dst->memory[dst->elem_size * index + 1], temp, \
			dst->elem_size);
		index++;
	}
	return (1);
}
