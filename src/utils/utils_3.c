/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:36:43 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/09 16:51:06 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strspn(const char *str1, const char *str2)
{
	size_t	i;
	size_t	j;
	int		match;

	i = 0;
	while (str1[i])
	{
		match = 0;
		j = 0;
		while (str2[j])
		{
			if (str1[i] == str2[j])
			{
				match = 1;
				break ;
			}
			j++;
		}
		if (!match)
			return (i);
		i++;
	}
	return (i);
}

void	error_exit(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && *stack_a)
		free_stack(stack_a);
	if (stack_b && *stack_b)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
