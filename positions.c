/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 00:41:42 by kriad             #+#    #+#             */
/*   Updated: 2026/01/28 03:03:02 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_positions(t_stack *s)
{
	t_node	*n;
	int		i;

	if (!s)
		return ;
	i = 0;
	n = s->top;
	while (n)
	{
		n->pos = i;
		i++;
		n = n->next;
	}
}

int	get_max_index(t_stack *s)
{
	t_node	*n;
	int		max;

	if (!s || !s->top)
		return (-1);
	n = s->top;
	max = n->index;
	while (n)
	{
		if (n->index > max)
			max = n->index;
		n = n->next;
	}
	return (max);
}
