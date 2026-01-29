/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kriad <kriad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:26:03 by kriad             #+#    #+#             */
/*   Updated: 2026/01/29 10:42:11 by kriad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	parse_args(ac, av, &a);
	assign_index(&a);
	chunk_sort(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
