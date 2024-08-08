/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:29:05 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/08 12:05:05 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_elements(t_node *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

long	convert_to_long(const char *nptr, int i, int sign)
{
	long	r;

	r = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (r > (LONG_MAX - (nptr[i] - '0')) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		r = (r * 10) + (nptr[i] - '0');
		i++;
	}
	return (r * sign);
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	return (convert_to_long(nptr, i, sign));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
