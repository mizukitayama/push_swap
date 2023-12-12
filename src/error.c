/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:41:56 by mtayama           #+#    #+#             */
/*   Updated: 2023/12/08 19:49:02 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_out_of_range_int(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		sign = sign - (2 * (*str == '-'));
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (true);
		num = num * 10 + (*str - '0');
		if (sign == 1 && num > INT_MAX)
			return (true);
		if (sign == -1 && -1 * num < INT_MIN)
			return (true);
		str++;
	}
	return (false);
}

static bool	is_duplicated(char *arg, t_stack **a)
{
	t_stack	*tmp;

	if (*a == NULL)
		return (false);
	tmp = *a;
	while (1)
	{
		if (tmp->content == ft_atoi(arg))
			return (true);
		tmp = tmp->next;
		if (tmp == *a)
			return (false);
	}
	return (false);
}

static bool	is_unauthorized_input(char *arg)
{
	if (*arg == '\0' || is_out_of_range_int(arg))
		return (true);
	if ((arg[0] == '-' || arg[0] == '+') && ft_isdigit(arg[1]))
		arg++;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (true);
		arg++;
	}
	return (false);
}

void	check_errors(char *arg, t_stack **a)
{
	if (is_unauthorized_input(arg) || is_duplicated(arg, a))
	{
		write(2, "Error\n", 6);
		free_list(a);
		exit(1);
	}
}
