/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instractions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:42:21 by mtayama           #+#    #+#             */
/*   Updated: 2023/12/08 19:50:23 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ノードが3つの時のみ
static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	first->next = third;
	second->prev->next = second;
	second->prev->prev = first;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	write(1, "sa\n", 3);
	swap(stack_a);
}
