/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:03:09 by kriad             #+#    #+#             */
/*   Updated: 2026/01/28 00:01:40 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*n;
	t_node	*l;

	if (!a || a->size < 2)
		return ;
	n = a->top;
	a->top = n->next;
	l = last_node(a->top);
	l->next = n;
	n->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b)
{
	t_node	*n;
	t_node	*l;

	if (!b || b->size < 2)
		return ;
	n = b->top;
	b->top = n->next;
	l = last_node(b->top);
	l->next = n;
	n->next = NULL;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	t_node	*n;
	t_node	*l;

	if (a && a->size >= 2)
	{
		n = a->top;
		a->top = n->next;
		l = last_node(a->top);
		l->next = n;
		n->next = NULL;
	}
	if (b && b->size >= 2)
	{
		n = b->top;
		b->top = n->next;
		l = last_node(b->top);
		l->next = n;
		n->next = NULL;
	}
	ft_putstr_fd("rr\n", 1);
}
