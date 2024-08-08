/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:15:46 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/08 11:58:20 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top_two_and_sort(t_node **stack_a, t_node **stack_b)
{
	while (count_elements(*stack_b) < 2)
	{
		if ((*stack_a)->order == 1 || (*stack_a)->order == 2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	ft_3_sort(stack_a);
	if ((*stack_b)->order < (*stack_b)->next->order)
		sb(stack_b);
}

void	ft_5_sort(t_node **stack_a, t_node **stack_b)
{
	order_nodes(*stack_a, 5);
	move_top_two_and_sort(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
