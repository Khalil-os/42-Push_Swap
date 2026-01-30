/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:37:46 by kriad             #+#    #+#             */
/*   Updated: 2026/01/30 16:32:43 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* utils */
int		ft_isdigit(int n);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	free_split(char **arr);
void	ft_putstr_fd(char *s, int fd);

/* errors */
void	error_exit(t_stack *a, t_stack *b);

/* parsing */
void	parse_args(int ac, char **av, t_stack *a);
int		is_sorted(t_stack *a);

/* stack */
t_node	*new_node(int value);
void	add_bottom(t_stack *s, t_node *node);
void	add_top(t_stack *s, t_node *node);
void	clear_stack(t_stack *s);
t_node	*last_node(t_node *n);

/* positions */
void	update_positions(t_stack *s);
int		get_max_index(t_stack *s);
int		get_pos_by_index(t_stack *s, int index);

/* operations */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* indexing */
void	assign_index(t_stack *a);
void	move_index_to_top(t_stack *s, int index);

/* small sort */
void	sort_small(t_stack *a, t_stack *b);

/* chunk sort */
void	chunk_sort(t_stack *a, t_stack *b);
int		get_chunk_size(int n);

#endif
