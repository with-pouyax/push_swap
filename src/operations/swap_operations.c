/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:33:44 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/08 11:54:20 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	t_node	*first;
	t_node	*second;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack_b = second;
	write(1, "sb\n", 3);
}

void	sa_ss(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack_a = second;
}

void	sb_ss(t_node **stack_b)
{
	t_node	*first;
	t_node	*second;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack_b = second;
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa_ss(stack_a);
	sb_ss(stack_b);
	write(1, "ss\n", 3);
}
