/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:56:19 by kriad             #+#    #+#             */
/*   Updated: 2026/01/27 16:02:31 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*n;

	if (!a || !b || b->size == 0)
		return ;
	n = b->top;
	b->top = n->next;
	b->size--;
	n->next = a->top;
	a->top = n;
	a->size++;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*n;

	if (!a || !b || a->size == 0)
		return ;
	n = a->top;
	a->top = n->next;
	a->size--;
	n->next = b->top;
	b->top = n;
	b->size++;
	ft_putstr_fd("pb\n", 1);
}
