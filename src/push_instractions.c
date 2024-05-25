/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instractions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:42:13 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/26 07:01:34 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	delete_head_node(t_stack **head)
{
	t_stack	*tmp_stack;

	if (head == NULL || *head == NULL)
		return ;
	tmp_stack = *head;
	if ((*head)->next == *head)
		*head = NULL;
	else
	{
		(*head)->next->prev = (*head)->prev;
		(*head)->prev->next = (*head)->next;
		*head = (*head)->next;
	}
	free(tmp_stack);
}

void	stack_node(t_stack **dst_stack, t_stack **src_stack)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
	{
		free_list(dst_stack);
		free_list(src_stack);
		exit(1);
	}
	new->content = (*src_stack)->content;
	new->index = (*src_stack)->index;
	if (*dst_stack == NULL)
	{
		new->next = new;
		new->prev = new;
	}
	else
	{
		new->next = *dst_stack;
		new->prev = (*dst_stack)->prev;
		(*dst_stack)->prev->next = new;
		(*dst_stack)->prev = new;
	}
	*dst_stack = new;
}

void	pa(t_stack **stack_a, t_stack **stack_b, int print_flg)
{
	if (print_flg == 1)
		write(1, "pa\n", 3);
	stack_node(stack_a, stack_b);
	delete_head_node(stack_b);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int print_flg)
{
	if (print_flg == 1)
		write(1, "pb\n", 3);
	stack_node(stack_b, stack_a);
	delete_head_node(stack_a);
}
