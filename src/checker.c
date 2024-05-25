/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 06:51:03 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/26 07:25:57 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cp;
	unsigned char	*s2_cp;

	i = 0;
	s1_cp = (unsigned char *)s1;
	s2_cp = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((s1_cp[i] || s2_cp[i]) && i < n)
	{
		if (s1_cp[i] > s2_cp[i])
		{
			return ((int)s1_cp[i] - s2_cp[i]);
		}
		else if (s1_cp[i] < s2_cp[i])
		{
			return ((int)s1_cp[i] - s2_cp[i]);
		}
		else
		{
			i++;
		}
	}
	return (0);
}

#include <string.h>
static void	check_instruction(char *line, t_stack **a, t_stack ** b)
{
	if (strncmp(line, "sa", 3) == 0)
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
			write(1, "Error\n", 6);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		printf("line: %s\n", line);
		if (!line)
			break ;
		check_instruction(line, a, b);
		free(line);
	}
	if (is_sorted(*a) && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

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