/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:08:46 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/08 11:59:29 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_nodes_array(t_node *stack, t_node **nodes, int size)
{
	t_node	*temp;
	int		i;

	temp = stack;
	i = 0;
	while (i < size)
	{
		if (temp == NULL)
			return (-1);
		nodes[i] = temp;
		temp = temp->next;
		i++;
	}
	return (0);
}

void	assign_orders(t_node **nodes, int size)
{
	int	i;
	int	j;
	int	order;

	i = 0;
	while (i < size)
	{
		order = 1;
		j = 0;
		while (j < size)
		{
			if (nodes[i]->data > nodes[j]->data)
				order++;
			j++;
		}
		nodes[i]->order = order;
		i++;
	}
}

int	order_nodes(t_node *stack, int size)
{
	int		result;
	t_node	**nodes;

	nodes = (t_node **)malloc(sizeof(t_node *) * size);
	if (nodes == NULL)
		return (-1);
	result = fill_nodes_array(stack, nodes, size);
	if (result == -1)
	{
		free(nodes);
		return (-1);
	}
	assign_orders(nodes, size);
	free(nodes);
	return (0);
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	assign_indexes(t_node *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (current->data > compare->data)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
