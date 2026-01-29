/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:43:33 by kriad             #+#    #+#             */
/*   Updated: 2026/01/27 15:53:57 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node	*n;
	t_node	*n2;

	if (!a || a->size < 2)
		return ;
	n = a->top;
	n2 = n->next;
	n->next = n2->next;
	n2->next = n;
	a->top = n2;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	t_node	*n;
	t_node	*n2;

	if (!b || b->size < 2)
		return ;
	n = b->top;
	n2 = n->next;
	n->next = n2->next;
	n2->next = n;
	b->top = n2;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	t_node	*n;
	t_node	*n2;

	if (a && a->size >= 2)
	{
		n = a->top;
		n2 = n->next;
		n->next = n2->next;
		n2->next = n;
		a->top = n2;
	}
	if (b && b->size >= 2)
	{
		n = b->top;
		n2 = n->next;
		n->next = n2->next;
		n2->next = n;
		b->top = n2;
	}
	ft_putstr_fd("ss\n", 1);
}
