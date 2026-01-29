/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:08:00 by kriad             #+#    #+#             */
/*   Updated: 2026/01/28 00:05:23 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->pos = -1;
	node->next = NULL;
	return (node);
}

void	add_bottom(t_stack *s, t_node *node)
{
	t_node	*last;

	if (!s || !node)
		return ;
	node->next = NULL;
	if (s->top == NULL)
	{
		s->top = node;
		s->size++;
		return ;
	}
	last = s->top;
	while (last->next != NULL)
		last = last->next;
	last->next = node;
	s->size++;
}

void	add_top(t_stack *s, t_node *node)
{
	if (!s || !node)
		return ;
	node->next = s->top;
	s->top = node;
	s->size++;
}

void	clear_stack(t_stack *s)
{
	t_node	*tmp;

	if (!s)
		return ;
	while (s->top)
	{
		tmp = s->top->next;
		free (s->top);
		s->top = tmp;
	}
	s->top = NULL;
	s->size = 0;
}

t_node	*last_node(t_node *n)
{
	t_node	*l;

	if (!n)
		return (NULL);
	l = n;
	while (l->next != NULL)
		l = l->next;
	return (l);
}
