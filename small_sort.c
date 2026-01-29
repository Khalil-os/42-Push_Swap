/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 00:45:36 by kriad             #+#    #+#             */
/*   Updated: 2026/01/28 01:37:18 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

static void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	last;

	top = a->top->index;
	mid = a->top->next->index;
	last = a->top->next->next->index;
	if (top > mid && top > last)
		ra(a);
	else if (mid > top && mid > last)
		rra(a);
	if (a->top->index > a->top->next->index)
		sa(a);
}

static void	sort_five(t_stack *a, t_stack *b)
{
	t_node	*n;
	int		target;

	target = 0;
	while (a->size > 3)
	{
		update_positions(a);
		n = a->top;
		while (n->index != target)
			n = n->next;
		while (n->pos != 0)
		{
			if (n->pos <= a->size / 2)
				ra(a);
			else
				rra(a);
			update_positions(a);
		}
		pb(a, b);
		target++;
	}
	sort_three(a);
	while (b->size)
		pa(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
}
