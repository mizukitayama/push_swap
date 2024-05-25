/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 07:46:09 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/26 07:47:17 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * スタックAからBへ移動させる関数の続き
 */
void	ft_move_b_judge(t_stack **stack_a, t_stack **stack_b, t_move *move)
{
	move->top_num = (*stack_a)->index;
	if (move->top_num >= move->search_num && move->top_num
		<= move->search_num_more - move->section_num)
		pb(stack_a, stack_b, 1);
	else if (move->top_num >= move->search_num
		&& move->top_num <= move->search_num_more)
	{
		pb(stack_a, stack_b, 1);
		rb(stack_b, 1);
	}
	else
	{
		ra(stack_a, 1);
	}
}
//TODO: ft_move_b_check関数のバグが治れば以下を使用。elseの中。
		// if (ft_move_b_check(*stack_a,
		// 		move->search_num, move->search_num_more))
		// 	ra(stack_a, 1);
		// else
		// {
		// 	rra(stack_a, 1);
		// }

/*
 * スタックBへ移動させたグループが、スタックAへ戻ったか判断する関数
 */
bool	ft_is_search_num(t_stack *stack_b, t_move *move
	, size_t move_section_count)
{
	int				search_num_min;
	int				search_num_max;
	t_stack			*tmp;
	unsigned int	i;

	search_num_max = move_section_count * move->section_num;
	search_num_min = search_num_max - (move->section_num - 1);
	if (move->section_count == move_section_count)
	{
		search_num_max = move->max_index;
		search_num_min = move->max_index
			- (move->max_index % move->section_num) + 1;
	}
	tmp = stack_b;
	i = 0;
	while (i < count_list(stack_b))
	{
		if (tmp->index >= search_num_min
			&& tmp->index <= search_num_max)
			return (true);
		tmp = tmp->next;
		i++;
	}
	return (false);
}

/*
 * スタックBからAへ戻す関数の続き2
 */
void	ft_move_a_flg_check(
	t_stack **stack_a, t_stack **stack_b, t_move *move)
{
	size_t	i_;

	if (move->a_move_flg == 0)
		pa(stack_a, stack_b, 1);
	else if (move->a_move_flg == 1)
	{
		pa(stack_a, stack_b, 1);
		sa(stack_a, 1);
		move->a_move_flg = 0;
	}
	else if (move->a_move_flg > 1)
	{
		i_ = 0;
		while (i_++ < move->a_move_flg)
			ra(stack_a, 1);
		pa(stack_a, stack_b, 1);
		i_ = 0;
		while (i_++ < move->a_move_flg)
			rra(stack_a, 1);
		move->a_move_flg = 0;
	}
	move->search_num = move->search_num_more;
	move->search_num_more = move->search_num - 1;
}

/*
 * スタックBからAへ戻す関数の続き1
 */
void	ft_move_a_judge(t_stack **stack_a, t_stack **stack_b, t_move *move)
{
	move->top_num = (*stack_b)->index;
	if (move->top_num == move->search_num)
	{
		ft_move_a_flg_check(stack_a, stack_b, move);
	}
	else if (move->top_num == move->search_num_more)
	{
		pa(stack_a, stack_b, 1);
		move->a_move_flg++;
		move->search_num_more--;
	}
	else
	{
		if (ft_move_a_check(*stack_b, move->search_num))
			rb(stack_b, 1);
		else
			rrb(stack_b, 1);
	}
}
