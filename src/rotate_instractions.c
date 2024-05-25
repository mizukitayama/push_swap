/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instractions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:42:19 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/26 07:03:56 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a, int print_flg)
{
	if (print_flg == 1)
		write(1, "ra\n", 3);
	if (!stack_a || !*stack_a)
		return ;
	*stack_a = (*stack_a)->next;
}

void	rra(t_stack **stack_a, int print_flg)
{
	if (print_flg == 1)
		write(1, "rra\n", 4);
	if (!stack_a || !*stack_a)
		return ;
	*stack_a = (*stack_a)->prev;
}

void	rb(t_stack **stack_b, int print_flg)
{
	if (print_flg == 1)
		write(1, "rb\n", 3);
	if (!stack_b || !*stack_b)
		return ;
	*stack_b = (*stack_b)->next;
}

void	rrb(t_stack **stack_b, int print_flg)
{
	if (print_flg == 1)
		write(1, "rrb\n", 4);
	if (!stack_b || !*stack_b)
		return ;
	*stack_b = (*stack_b)->prev;
}

void	rr(t_stack **stack_a, t_stack **stack_b, int print_flag)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print_flag == 1)
		write(1, "rr\n", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print_flag)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print_flag == 1)
		write(1, "rrr\n", 4);
}
