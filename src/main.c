/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:20:06 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/08 11:46:36 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **stack_a, t_node **stack_b)
{
	int	count;

	count = count_elements(*stack_a);
	if (count == 2)
		ft_2_sort(stack_a);
	else if (count == 3)
		ft_3_sort(stack_a);
	else if (count == 4)
		ft_4_sort(stack_a, stack_b);
	else if (count == 5)
		ft_5_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		split_and_process(&stack_a, av[i]);
		i++;
	}
	assign_indexes(stack_a);
	if (is_sorted(stack_a) || count_elements(stack_a) == 1)
	{
		free_stack(&stack_a);
		return (0);
	}
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
