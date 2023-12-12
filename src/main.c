/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:41:51 by mtayama           #+#    #+#             */
/*   Updated: 2023/12/08 19:41:52 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// #include <stdio.h> //TODO: delete
// void	print_list(t_stack *head)
// {
// 	t_stack	*tmp;

// 	if (!head)
// 		return ;
// 	tmp = head;
// 	while (1)
// 	{
// 		printf("content: [%d]\n", tmp->content);
// 		tmp = tmp->next;
// 		if (tmp == head)
// 			return ;
// 	}
// }

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	unsigned int	stack_length;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(1);
	stack_length = create_stack(&a, &argv[1]);
	assign_unique_indices(a);
	if (stack_length <= 5)
		mini_sort(&a, &b, stack_length);
	else
		radix_sort(&a, &b, stack_length);
	free_list(&a);
	free_list(&b);
	return (0);
}

// CRASH

// ./push_swap ""

// __attribute__ ((destructor)) void destructor()
// {
// 	system("leaks -q push_swap");
// }
