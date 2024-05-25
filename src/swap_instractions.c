/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instractions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:42:21 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/26 07:44:16 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, int print_flg)
{
	int	next_content;
	int	next_index;

	next_content = (*(*stack_a)->next).content;
	next_index = (*(*stack_a)->next).index;
	(*(*stack_a)->next).content = (*stack_a)->content;
	(*(*stack_a)->next).index = (*stack_a)->index;
	(*stack_a)->content = next_content;
	(*stack_a)->index = next_index;
	if (print_flg == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int print_flg)
{
	int	next_content;
	int	next_index;

	next_content = (*(*stack_b)->next).content;
	next_index = (*(*stack_b)->next).index;
	(*(*stack_b)->next).content = (*stack_b)->content;
	(*(*stack_b)->next).index = (*stack_b)->index;
	(*stack_b)->content = next_content;
	(*stack_b)->index = next_index;
	if (print_flg == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int print_flg)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print_flg == 1)
		write(1, "ss\n", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print_flag)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print_flag == 1)
		write(1, "rrr\n", 4);
}
