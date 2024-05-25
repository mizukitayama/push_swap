/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 02:13:49 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/26 07:46:51 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * スタックAからBへ移動させる関数
 */
static void	move_a_to_b(t_stack **stack_a, t_stack **stack_b, t_move *move)
{
	unsigned int	i;
	unsigned int	stack_a_size;

	while (count_list(*stack_a) != 0)
	{
		move->search_num = 1 + move->search_num_more;
		move->search_num_more = (move->section_num * 2)
			+ (move->search_num - 1);
		i = 0;
		stack_a_size = count_list(*stack_a);
		while (i < stack_a_size)
		{
			ft_move_b_judge(stack_a, stack_b, move);
			i++;
		}
	}
}

/*
 * スタックBからAへ戻す関数
 */
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b, t_move *move)
{
	unsigned int	move_section_count;

	move_section_count = move->section_count;
	while (count_list(*stack_b) != 0)
	{
		move->a_move_flg = 0;
		while (ft_is_search_num(*stack_b, move, move_section_count))
		{
			ft_move_a_judge(stack_a, stack_b, move);
		}
		move_section_count--;
	}
}

/*
 * 並び変える要素数が7個以上の場合のソートアルゴリズム
 */
void	long_sort(t_stack **stack_a, t_stack **stack_b, unsigned int max_index)
{
	t_move	move;

	move.max_index = max_index;
	if (move.max_index <= 110)
		move.section_num = 15;
	else if (move.max_index <= 510)
		move.section_num = 32;
	move.section_count = max_index / move.section_num;
	if (max_index % move.section_num != 0)
		move.section_count++;
	move.search_num = 0;
	move.search_num_more = 0;
	move_a_to_b(stack_a, stack_b, &move);
	move.search_num = max_index;
	move.search_num_more = max_index - 1;
	move_b_to_a(stack_a, stack_b, &move);
}
