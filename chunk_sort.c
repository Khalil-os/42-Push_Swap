/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 01:45:24 by kriad             #+#    #+#             */
/*   Updated: 2026/01/29 22:02:27 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int n)
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

static int	push_one_from_chunk(t_stack *a, t_stack *b,
									int chunk_start, int chunk_end)
{
	t_node	*n;
	int		idx;
	int		mid;

	update_positions(a);
	n = a->top;
	mid = chunk_start + (chunk_end - chunk_start) / 2;
	while (n)
	{
		if (n->index >= chunk_start && n->index <= chunk_end)
		{
			while (n->pos != 0)
			{
				if (n->pos <= a->size / 2)
					ra(a);
				else
					rra(a);
				update_positions(a);
			}
			idx = n->index;
			pb(a, b);
			if (idx < mid)
				rb(b);
			return (1);
		}
		n = n->next;
	}
	return (0);
}

static void	push_chunks(t_stack *a, t_stack *b, int chunk)
{
	int	chunk_start;
	int	chunk_end;

	chunk_start = 0;
	chunk_end = chunk - 1;
	while (a->size > 0)
	{
		if (!push_one_from_chunk(a, b, chunk_start, chunk_end))
		{
			chunk_start += chunk;
			chunk_end += chunk;
		}
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	t_node	*n;
	int		max;

	while (b->size > 0)
	{
		max = get_max_index(b);
		update_positions(b);
		n = b->top;
		while (n && n->index != max)
			n = n->next;
		while (n && n->pos != 0)
		{
			if (n->pos <= b->size / 2)
				rb(b);
			else
				rrb(b);
			update_positions(b);
		}
		pa(a, b);
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk;

	if (!a || a->size <= 1 || is_sorted(a))
		return ;
	if (a->size <= 5)
	{
		sort_small(a, b);
		return ;
	}
	chunk = get_chunk_size(a->size);
	push_chunks(a, b, chunk);
	push_back_to_a(a, b);
}
