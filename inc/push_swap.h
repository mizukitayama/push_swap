/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:42:35 by mtayama           #+#    #+#             */
/*   Updated: 2023/12/08 19:42:36 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

unsigned int	create_stack(t_stack **a, char **argv);
void			free_list(t_stack **stack);
void			assign_unique_indices(t_stack *head);
void			mini_sort(t_stack **stack_a, t_stack **stack_b, \
unsigned int num_args);
void			radix_sort(t_stack **stack_a, t_stack **stack_b, \
unsigned int num_args);
int				is_sorted(t_stack *stack_a);
void			pb(t_stack **stack_a, t_stack **stack_b);
void			pa(t_stack **stack_a, t_stack **stack_b);
void			ra(t_stack **stack_a);
void			rra(t_stack **stack_a);
void			sa(t_stack **stack_a);
void			check_errors(char *arg, t_stack **a);
int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				get_next_min_index(t_stack **head, int min_index);
int				get_distance_to_min(t_stack **stack, int min_index);

#endif
