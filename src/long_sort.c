/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 02:13:49 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/26 07:02:14 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/* TODO: 
	array_sizeを取得する。
	done_t_moveの構造体を作る
	done_各スタックの要素数を求める関数を作る
	done_どっちにロテートしたほうが良いか判断する感ん数を作る
*/


/*
 * スタックAからBへ移動させる関数の続き
 */
static void	ft_move_b_judge(t_stack **stack_a, t_stack **stack_b, t_move *move)
{
	move->top_num = (*stack_a)->index;
	// printf("move->top_num = %d, move->search_num = %d, move->search_num_more = %d, move->section_num = %d\n", move->top_num, move->search_num, move->search_num_more, move->section_num);
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
		// if (ft_move_b_check(*stack_a,
		// 		move->search_num, move->search_num_more))
		// 	ra(stack_a, 1);
		// else
		// {
		// 	rra(stack_a, 1);
		// }
	}
}

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
		// printf("222 move->search_num = %d, move->search_num_more = %d\n", move->search_num, move->search_num_more);
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
 * スタックBへ移動させたグループが、スタックAへ戻ったか判断する関数
 */
static bool	ft_is_search_num(t_stack *stack_b, t_move *move
	, size_t move_section_count)
{
	int		search_num_min;
	int		search_num_max;
	t_stack	*tmp;
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
static void	ft_move_a_flg_check(t_stack **stack_a, t_stack **stack_b, t_move *move)
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
		while (i_++ < move->a_move_flg){
			rra(stack_a, 1);
		}
		move->a_move_flg = 0;
	}
	move->search_num = move->search_num_more;
	move->search_num_more = move->search_num - 1;
}

/*
 * スタックBからAへ戻す関数の続き1
 */
static void	ft_move_a_judge(t_stack **stack_a, t_stack **stack_b, t_move *move)
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
