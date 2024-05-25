/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:42:35 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/26 07:50:00 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_stack{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_move {
	unsigned int	section_count;
	int				section_num;
	int				top_num;
	int				search_num;
	int				search_num_more;
	unsigned int	a_move_flg;
	unsigned int	max_index;
}	t_move;
char			*get_next_line(int fd);
unsigned int	create_stack(t_stack **a, char **argv);
void			free_list(t_stack **stack);
void			assign_unique_indices(t_stack *head);
void			mini_sort(t_stack **stack_a, t_stack **stack_b, \
unsigned int num_args);
void			radix_sort(t_stack **stack_a, t_stack **stack_b, \
unsigned int num_args);
int				is_sorted(t_stack *stack_a);
void			check_errors(char *arg, t_stack **a);
int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);
char			**ft_split(char const *s, char c);
char			*ft_substr(char *s, unsigned int start, size_t len);
int				get_next_min_index(t_stack **head, int min_index);
int				get_distance_to_min(t_stack **stack, int min_index);
void			long_sort(t_stack **stack_a, t_stack **stack_b, \
unsigned int max_index);
bool			ft_is_search_num(t_stack *stack_b, t_move *move, \
size_t move_section_count);
void			ft_move_b_judge(t_stack **stack_a, t_stack **stack_b, \
t_move *move);
void			ft_move_a_flg_check(t_stack **stack_a, t_stack **stack_b, \
t_move *move);
void			ft_move_a_judge(t_stack **stack_a, t_stack **stack_b, \
t_move *move);

// instructions
void			pb(t_stack **stack_a, t_stack **stack_b, int print_flg);
void			pa(t_stack **stack_a, t_stack **stack_b, int print_flg);
void			ra(t_stack **stack_a, int print_flg);
void			rb(t_stack **stack_b, int print_flg);
void			rra(t_stack **stack_a, int print_flg);
void			rrb(t_stack **stack_b, int print_flg);
void			rr(t_stack **stack_a, t_stack **stack_b, int print_flg);
void			rrr(t_stack **stack_a, t_stack **stack_b, int print_flg);
void			sa(t_stack **stack_a, int print_flg);
void			sb(t_stack **stack_b, int print_flg);
void			ss(t_stack **stack_a, t_stack **stack_b, int print_flg);

unsigned int	count_list(t_stack *head);
bool			ft_move_b_check(t_stack *stack_a, int min, int max);
bool			ft_move_a_check(t_stack *stack_b, int search_num);

size_t			ft_strlen(char *str);
char			*ft_strchr(char *s, int c);
char			*combine_strs(char *save, char *buf);

#endif
