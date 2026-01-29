/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:04:39 by kriad             #+#    #+#             */
/*   Updated: 2026/01/27 15:42:19 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicates(t_stack *a)
{
	t_node	*i;
	t_node	*j;

	if (!a || !a->top)
		return (0);
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

static int	is_number(char *s)
{
	int	i;

	if (!s || !s[0])
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	parse_one_arg(char *arg, t_stack *a)
{
	char	**s;
	long	n;
	int		j;

	s = ft_split(arg, ' ');
	if (!s || !s[0])
		(free_split(s), error_exit(a, NULL));
	j = 0;
	while (s[j])
	{
		if (!is_number(s[j]))
			(free_split(s), error_exit(a, NULL));
		n = ft_atoi(s[j]);
		if (n > 2147483647)
			(free_split(s), error_exit(a, NULL));
		add_bottom(a, new_node((int)n));
		j++;
	}
	free_split(s);
}

int	is_sorted(t_stack *a)
{
	t_node	*l;

	if (!a || !a->top)
		return (1);
	l = a->top;
	while (l->next)
	{
		if (l->value > l->next->value)
			return (0);
		l = l->next;
	}
	return (1);
}

void	parse_args(int ac, char **av, t_stack *a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		parse_one_arg(av[i], a);
		i++;
	}
	if (has_duplicates(a))
		error_exit(a, NULL);
}
