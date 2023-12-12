/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instractions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:42:19 by mtayama           #+#    #+#             */
/*   Updated: 2023/12/08 19:42:20 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	write(1, "ra\n", 3);
	if (!stack_a || !*stack_a)
		return ;
	*stack_a = (*stack_a)->next;
}

void	rra(t_stack **stack_a)
{
	write(1, "rra\n", 4);
	if (!stack_a || !*stack_a)
		return ;
	*stack_a = (*stack_a)->prev;
}
