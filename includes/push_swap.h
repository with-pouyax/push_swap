/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:11:31 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/08 11:45:15 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>

typedef struct s_node
{
	int				data;
	int				index;
	int				order;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

void	assign_indexes(t_node *stack);
int		list_size(t_node *stack);
int		is_sorted(t_node *stack);
void	radix_sort(t_node **stack_a, t_node **stack_b);

//operations
void	pb(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack_a);
void	sa_ss(t_node **stack_a);
void	sb(t_node **stack_b);
void	sb_ss(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	ra_ss(t_node **stack_a);
void	rb(t_node **stack_b);
void	rb_ss(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rra_ss(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrb_ss(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

// Function declarations
void	split_and_process(t_node **head, char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		is_duplicate(t_node *node, int value);
int		push(t_node **node, int value);
int		process_argument(t_node **node, char *arg);
int		count_elements(t_node *stack);
void	except_3(t_node **stack_a, t_node **stack_b);
int		order_nodes(t_node *stack, int size);
void	ft_2_sort(t_node **stack_a);
void	ft_3_sort(t_node **stack_a);
void	ft_4_sort(t_node **stack_a, t_node **stack_b);
void	ft_5_sort(t_node **stack_a, t_node **stack_b);

// Additional function declarations
void	check_length(t_node **node, int len);
void	check_number_range(t_node **node, long num);
void	check_valid_chars(t_node **node, char *arg);
void	skip_leading_zeros(char **arg, int *len);
void	free_stack(t_node **stack);
void	error_exit(t_node **stack_a, t_node **stack_b);
long	ft_atol(const char *nptr);
size_t	ft_strlen(const char *s);
void	check_leading_zero_negative(t_node **node, char *arg);

#endif
