/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:42:06 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/26 04:02:40 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_list(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (*stack == NULL)
		return ;
	current = (*stack)->next;
	while (1)
	{
		next = current->next;
		free(current);
		if (current == (*stack))
			return ;
		current = next;
	}
}

static void	create_node(t_stack **head, int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
	{
		free_list(head);
		exit(1);
	}
	new->content = num;
	if (*head == NULL)
	{
		new->next = new;
		new->prev = new;
		*head = new;
	}
	else
	{
		new->next = *head;
		new->prev = (*head)->prev;
		(*head)->prev->next = new;
		(*head)->prev = new;
	}
}

unsigned int	create_stack(t_stack **a, char **argv)
{
	unsigned int	stack_length;
	unsigned int	i;

	stack_length = 0;
	i = 0;
	while (argv[i])
	{
		check_errors(argv[i], a);
		create_node(a, ft_atoi(argv[i]));
		i++;
		stack_length++;
	}
	return (stack_length);
}
