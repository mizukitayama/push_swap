#include "push_swap.h"

unsigned int	count_list(t_stack *head)
{
	t_stack	*tmp;
	unsigned int		count;

	if (!head)
		return (0);
	tmp = head;
	count = 0;
	while (1)
	{
		count++;
		tmp = tmp->next;
		if (tmp == head)
			break ;
	}
	return (count);
}

/*
 * 目的の値まで、rotateかreverse_rotateか判断する関数（スタックBへ移動させるとき専用）
 * true = rotate
 * false = reverse_rotate
 */
bool	ft_move_b_check(t_stack *stack_a, int min, int max)
{
	size_t	rotate_count;
	size_t	reverse_rotate_count;
	t_stack	*tmp;

	rotate_count = 0;
	tmp = stack_a;
	while (tmp->index < min || tmp->index > max)
	{
		tmp = tmp->next;
		rotate_count++;
		if (tmp == stack_a)
			break ;
	}
	reverse_rotate_count = 0;
	tmp = stack_a;
	while (tmp->index < min || tmp->index > max)
	{
		tmp = tmp->prev;
		reverse_rotate_count++;
		if (tmp == stack_a)
			break ;
	}
	if (rotate_count < reverse_rotate_count)
		return (true);
	else
		return (false);
}

/*
 * 目的の値まで、rotateかreverse_rotateか判断する関数（スタックAへ戻すとき専用）
 * true = rotate
 * false = reverse_rotate
 */
bool	ft_move_a_check(t_stack *stack_b, int search_num)
{
	size_t	rotate_count;
	size_t	reverse_rotate_count;
	t_stack	*tmp;

	tmp = stack_b;
	rotate_count = 0;
	while (tmp->index != search_num)
	{
		tmp = tmp->next;
		if (tmp == stack_b)
			break ;
		rotate_count++;
	}
	// printf("rotate_count: %zu\n", rotate_count);
	tmp = stack_b;
	reverse_rotate_count = 0;
	while (tmp->index != search_num)
	{
		tmp = tmp->prev;
		if (tmp == stack_b)
			break ;
		reverse_rotate_count++;
	}
	// printf("reverse_rotate_count: %zu\n", reverse_rotate_count);
	if (rotate_count < reverse_rotate_count)
		return (true);
	else
		return (false);
}
