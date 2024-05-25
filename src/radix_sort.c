/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:42:17 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/26 07:01:50 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_smaller_elements_count(t_stack *target_node)
{
	t_stack	*iterator;
	int		smaller_count;

	smaller_count = 0;
	iterator = target_node->next;
	while (1)
	{
		if (iterator->content < target_node->content)
			smaller_count++;
		iterator = iterator->next;
		if (iterator == target_node)
			break ;
	}
	return (smaller_count + 1);
}

void	assign_unique_indices(t_stack *head)
{
	t_stack	*iterator;

	iterator = head;
	while (1)
	{
		iterator->index = calculate_smaller_elements_count(iterator);
		iterator = iterator->next;
		if (iterator == head)
			break ;
	}
}

int	is_sorted(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a->next;
	while (1)
	{
		if ((tmp->prev->index) > (tmp->index))
			return (0);
		tmp = tmp->next;
		if (tmp == stack_a)
			return (1);
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, unsigned int num_args)
{
	unsigned int	i;
	unsigned int	bits;

	bits = 1;
	while (!is_sorted(*stack_a))
	{
		i = 0;
		while (i < num_args)
		{
			if (!((*stack_a)->index & bits))
				pb(stack_a, stack_b, 1);
			else
				ra(stack_a, 1);
			i++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, 1);
		bits = bits << 1;
	}
}
