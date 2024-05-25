/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:42:10 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/26 07:00:43 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_sort_3_nodes(t_stack **stack_a, int min, \
int next_min, t_stack *head)
{
	if (head->index == min && head->next->index != next_min)
	{
		ra(stack_a, 1);
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack_a, 1);
		else
			rra(stack_a, 1);
	}
	else
	{
		if (head->next->index == min)
			ra(stack_a, 1);
		else
		{
			sa(stack_a, 1);
			rra(stack_a, 1);
		}
	}
}

static void	sort_3_nodes(t_stack **stack_a)
{
	t_stack		*head;
	int			min;
	int			next_min;

	head = *stack_a;
	min = get_next_min_index(stack_a, -1);
	next_min = get_next_min_index(stack_a, min);
	execute_sort_3_nodes(stack_a, min, next_min, head);
}

static void	sort_4_nodes(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance_to_min(stack_a, get_next_min_index(stack_a, -1));
	if (distance == 1 || distance == 2)
		ra(stack_a, 1);
	if (distance == 2)
		ra(stack_a, 1);
	if (distance == 3)
		rra(stack_a, 1);
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b, 1);
	sort_3_nodes(stack_a);
	pa(stack_a, stack_b, 1);
}

static void	sort_5_nodes(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance_to_min(stack_a, get_next_min_index(stack_a, -1));
	if (distance == 1 || distance == 2)
		ra(stack_a, 1);
	if (distance == 2)
		ra(stack_a, 1);
	if (distance == 3)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
	}
	if (distance == 4)
		rra(stack_a, 1);
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b, 1);
	sort_4_nodes(stack_a, stack_b);
	pa(stack_a, stack_b, 1);
}

void	mini_sort(t_stack **stack_a, t_stack **stack_b, \
unsigned int node_length)
{
	if (is_sorted(*stack_a))
		return ;
	if (node_length == 2)
		ra(stack_a, 1);
	else if (node_length == 3)
		sort_3_nodes(stack_a);
	else if (node_length == 4)
		sort_4_nodes(stack_a, stack_b);
	else if (node_length == 5)
		sort_5_nodes(stack_a, stack_b);
}
