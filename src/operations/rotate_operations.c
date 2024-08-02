/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:30:02 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/01 11:33:07 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a)
{
	t_node	*first;
	t_node	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	last = first;
	while (last->next != NULL)
		last = last->next;
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	t_node	*first;
	t_node	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;

	first = *stack_b;
	last = first;
	while (last->next != NULL)
		last = last->next;
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	ra_ss(t_node **stack_a)
{
	t_node	*first;
	t_node	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	last = first;
	while (last->next != NULL)
		last = last->next;
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rb_ss(t_node **stack_b)
{
	t_node	*first;
	t_node	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	last = first;
	while (last->next != NULL)
		last = last->next;
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra_ss(stack_a);
	rb_ss(stack_b);
	write(1, "rr\n", 3);
}