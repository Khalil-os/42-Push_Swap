/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 00:23:43 by kriad             #+#    #+#             */
/*   Updated: 2026/01/30 16:51:03 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_min_unindexed(t_stack *a)
{
	t_node	*n;
	t_node	*min;

	if (!a || !a->top)
		return (NULL);
	min = NULL;
	n = a->top;
	while (n)
	{
		if (n->index == -1)
		{
			if (!min || n->value < min->value)
				min = n;
		}
		n = n->next;
	}
	return (min);
}

int	get_pos_by_index(t_stack *s, int index)
{
	t_node	*n;

	update_positions(s);
	n = s->top;
	while (n)
	{
		if (n->index == index)
			return (n->pos);
		n = n->next;
	}
	return (-1);
}

void	move_index_to_top(t_stack *s, int index)
{
	int	pos;

	pos = get_pos_by_index(s, index);
	while (pos > 0)
	{
		if (pos <= s->size / 2)
			rb(s);
		else
			rrb(s);
		pos = get_pos_by_index(s, index);
	}
}

void	assign_index(t_stack *a)
{
	t_node	*n;
	int		i;

	i = 0;
	n = get_min_unindexed(a);
	while (n)
	{
		n->index = i;
		i++;
		n = get_min_unindexed(a);
	}	
}

int	get_chunk_size(int n)
{
	if (n <= 5)
		return (n);
	else if (n <= 20)
		return (n / 2);
	else if (n <= 100)
		return (20);
	else
		return (35);
}
