/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:16:05 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/01 14:57:04 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_length(t_node **node, int len)
{
	if (!len)
		error_exit(node, NULL);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' || \
	c == '\r');
}

int	is_duplicate(t_node *node, int value)
{
	t_node	*curr;

	curr = node;
	while (curr)
	{
		if (curr->data == value)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	push(t_node **node, int value)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (1);
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!*node)
		*node = new_node;
	else
	{
		curr = *node;
		while (curr->next)
			curr = curr->next;
		curr->next = new_node;
		new_node->prev = curr;
	}
	return (0);
}