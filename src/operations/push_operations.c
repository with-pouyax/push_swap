/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:25:20 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/01 11:25:56 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a != NULL)
		(*stack_a)->prev = NULL;
	temp->next = *stack_b;
	if (*stack_b != NULL)
		(*stack_b)->prev = temp;
	*stack_b = temp;
	write(1, "pb\n", 3);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b != NULL)
		(*stack_b)->prev = NULL;
	temp->next = *stack_a;
	if (*stack_a != NULL)
		(*stack_a)->prev = temp;
	*stack_a = temp;
	write(1, "pa\n", 3);
}