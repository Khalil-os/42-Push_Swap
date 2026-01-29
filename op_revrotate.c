/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 00:03:48 by kriad             #+#    #+#             */
/*   Updated: 2026/01/28 00:12:24 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node	*n;
	t_node	*l;

	if (!a || a->size < 2)
		return ;
	n = a->top;
	l = last_node(a->top);
	while (n->next != l)
		n = n->next;
	n->next = NULL;
	l->next = a->top;
	a->top = l;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b)
{
	t_node	*n;
	t_node	*l;

	if (!b || b->size < 2)
		return ;
	n = b->top;
	l = last_node(b->top);
	while (n->next != l)
		n = n->next;
	n->next = NULL;
	l->next = b->top;
	b->top = l;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	t_node	*n;
	t_node	*l;

	if (a && a->size >= 2)
	{
		n = a->top;
		l = last_node(a->top);
		while (n->next != l)
			n = n->next;
		n->next = NULL;
		l->next = a->top;
		a->top = l;
	}
	if (b && b->size >= 2)
	{
		n = b->top;
		l = last_node(b->top);
		while (n->next != l)
			n = n->next;
		n->next = NULL;
		l->next = b->top;
		b->top = l;
	}
	ft_putstr_fd("rrr\n", 1);
}
