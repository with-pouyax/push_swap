/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:26:09 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/08 11:51:59 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack_a)
{
	t_node	*last;
	t_node	*second_last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = *stack_a;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack_a;
	(*stack_a)->prev = last;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	t_node	*first;
	t_node	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	first = last;
	*stack_b = last;
	last->prev->next = NULL;
	last->prev = NULL;
	first->next = first;
	write(1, "rrb\n", 4);
}

void	rra_ss(t_node **stack_a)
{
	t_node	*first;
	t_node	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	first = last;
	*stack_a = last;
	last->prev->next = NULL;
	last->prev = NULL;
	first->next = first;
}

void	rrb_ss(t_node **stack_b)
{
	t_node	*first;
	t_node	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	first = last;
	*stack_b = last;
	last->prev->next = NULL;
	last->prev = NULL;
	first->next = first;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra_ss(stack_a);
	rrb_ss(stack_b);
	write(1, "rrr\n", 4);
}
