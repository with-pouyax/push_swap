/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_3_4sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:05:02 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/01 13:14:31 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_2_sort(t_node **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}


void	check_and_sort(t_node **stack_a, int order1, int order2, int order3)
{
	if (order1 == 1 && order2 == 2 && order3 == 3)
		return ;
	if (order1 == 1 && order2 == 3)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (order1 == 2 && order2 == 1)
		sa(stack_a);
	else if (order1 == 2 && order2 == 3)
		rra(stack_a);
	else if (order1 == 3 && order2 == 2)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (order1 == 3 && order2 == 1)
		ra(stack_a);
}

void	ft_3_sort(t_node **stack_a)
{
	int	order1;
	int	order2;
	int	order3;

	order_nodes(*stack_a, 3);
	order1 = (*stack_a)->order;
	order2 = (*stack_a)->next->order;
	order3 = (*stack_a)->next->next->order;
	check_and_sort(stack_a, order1, order2, order3);
}

void	ft_4_sort(t_node **stack_a, t_node **stack_b)
{
	order_nodes(*stack_a, 4);

	if ((*stack_a)->order == 1)
		pb(stack_a, stack_b);
	else if ((*stack_a)->next->order == 1)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->order == 1)
	{
		ra(stack_a);
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	ft_3_sort(stack_a);
	pa(stack_a, stack_b);
}
