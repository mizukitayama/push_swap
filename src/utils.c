/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:42:22 by mtayama           #+#    #+#             */
/*   Updated: 2023/12/08 19:42:23 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_min_index(t_stack **head, int min_index)
{
	t_stack		*tmp;
	int			min;

	tmp = *head;
	min = tmp->index;
	while (1)
	{
		if ((tmp->index < min) && tmp->index != min_index)
			min = tmp->index;
		tmp = tmp->next;
		if (tmp == *head)
			break ;
	}
	return (min);
}

int	get_distance_to_min(t_stack **stack, int min_index)
{
	t_stack	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (1)
	{
		if (head->index == min_index)
			break ;
		head = head->next;
		if (head == *stack)
			break ;
		distance++;
	}
	return (distance);
}

static int	my_atoi(char *nptr, long i, long sign)
{
	size_t	j;

	j = 0;
	while (nptr[j] && ft_isdigit((int)nptr[j]))
	{
		i = (i * 10) + (nptr[j] - 48);
		if ((i > (LONG_MAX / 10) && nptr[j + 1] != '\0')
			|| ((i == (LONG_MAX / 10))
				&& ((long)(nptr[j + 1] - 48) > (LONG_MAX % 10))))
		{
			if (sign == 1)
			{
				return ((int)LONG_MAX);
			}
			if (sign == -1)
				return ((int)LONG_MIN);
		}
		j++;
	}
	return ((int)i * sign);
}

int	ft_atoi(const char *nptr)
{
	long	sign;
	long	i;

	sign = 1;
	i = 0;
	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r' || *nptr == ' ')
	{
		nptr++;
	}
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		nptr++;
	}
	return (my_atoi((char *)nptr, i, sign));
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
