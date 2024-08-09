/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:39:35 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/09 16:50:31 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_number_range(t_node **node, long num)
{
	if (num > INT_MAX || num < INT_MIN)
		error_exit(node, NULL);
}

void	check_valid_chars(t_node **node, char *arg)
{
	int	i;

	i = 0;
	if ((arg[i] == '-' || arg[i] == '+') && arg[i + 1] != '\0')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			error_exit(node, NULL);
		i++;
	}
}

void	check_leading_zero_negative(t_node **node, char *arg)
{
	if (arg[0] == '-' && arg[1] == '0')
	{
		error_exit(node, NULL);
	}
}

int	process_argument(t_node **node, char *arg)
{
	int		len;
	long	num;
	char	*original_arg;

	original_arg = arg;
	check_leading_zero_negative(node, arg);
	len = ft_strlen(arg);
	num = ft_atol(arg);
	check_length(node, len);
	check_number_range(node, num);
	check_valid_chars(node, arg);
	if (is_duplicate(*node, (int)num))
		error_exit(node, NULL);
	if (push(node, (int)num) == 1)
		return (1);
	return (0);
}

void	split_and_process(t_node **head, char *str)
{
	char	*start;
	char	*end;
	char	temp;

	if (str == NULL || ft_strlen(str) == 0 || \
	ft_strspn(str, " \t\n\v\f\r") == ft_strlen(str))
		error_exit(head, NULL);
	start = str;
	while (*start)
	{
		while (*start && ft_isspace(*start))
			start++;
		if (!*start)
			break ;
		end = start;
		while (*end && !ft_isspace(*end))
			end++;
		temp = *end;
		*end = '\0';
		if (process_argument(head, start) == 1)
			free_stack(head);
		*end = temp;
		start = end;
	}
}
