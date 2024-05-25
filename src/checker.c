/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 06:51:03 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/26 06:53:39 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_stack **a, t_stack **b)
{
	char	*line;

	while (line = get_next_line(0) > 0)
	{
		if (ft_strncmp(line, "sa", 3) == 0)
			sa(a, 0);
		else if (ft_strncmp(line, "sb", 3) == 0)
			sb(b, 0);
		else if (ft_strncmp(line, "ss", 3) == 0)
			ss(a, b, 0);
		else if (ft_strncmp(line, "pa", 3) == 0)
			pa(a, b, 0);
		else if (ft_strncmp(line, "pb", 3) == 0)
			pb(a, b, 0);
		else if (ft_strncmp(line, "ra", 3) == 0)
			ra(a, 0);
		else if (ft_strncmp(line, "rb", 3) == 0)
			rb(b, 0);
		else if (ft_strncmp(line, "rr", 3) == 0)
			rr(a, b, 0);
		else if (ft_strncmp(line, "rra", 4) == 0)
			rra(a, 0);
		else if (ft_strncmp(line, "rrb", 4) == 0)
			rrb(b, 0);
		else if (ft_strncmp(line, "rrr", 4) == 0)
			rrr(a, b, 0);
		else
			ft_error();
		free(line);
	}
	if (is_sorted(*a) && !*b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);

}

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
	checker(&a, &b);
	free_list(&a);
	free_list(&b);
	return (0);
}