/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:18:52 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/01 13:24:20 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_node *stack)
{
	int	max;
	int	max_bits;

	max = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	bit_position;
	int	total_elements;
	int	max_bits;
	int	count;

	bit_position = 0;
	total_elements = count_elements(*stack_a);
	max_bits = get_max_bits(*stack_a);
	while (bit_position < max_bits)
	{
		count = 0;
		while (count < total_elements)
		{
			if (((*stack_a)->index >> bit_position) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			count++;
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		bit_position++;
	}
}