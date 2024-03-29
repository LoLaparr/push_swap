/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:19:10 by lolaparr          #+#    #+#             */
/*   Updated: 2023/03/27 15:52:55 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <limits.h>

# define INT_MAXI 2147483647
# define INT_MINI -2147483648

typedef struct s_lst
{
	int				content;
	int				index;
	int				pos;
	int				pos_target;
	int				cost_a;
	int				cost_b;
	struct s_lst	*next;
}					t_lst;

int					ft_make_stack(int ac, char **av, t_lst **list_a);
t_lst				*ft_new_lst(long long int content);
t_lst				*ft_last_lst(t_lst *lst);
void				ft_add_back_lst(t_lst **lst, t_lst *new);
int					ft_check_all(int ac, char **str);
int					ft_check_len_digit(char **str);
int					ft_check_digit(char **str);
int					ft_check_double(t_lst **stack_a);
int					ft_size_of_stack(t_lst *stack_a);
void				ft_do_index(t_lst *stack_a, int stack_size);
void				sa(t_lst **list_a, int nb);
void				sb(t_lst **list_b, int nb);
void				ss(t_lst **list_a, t_lst **list_b);
void				ra(t_lst **list_a, int nb);
void				rb(t_lst **list_b, int nb);
void				rr(t_lst **list_a, t_lst **list_b);
void				rra(t_lst **list_a, int nb);
void				rrb(t_lst **list_b, int nb);
void				rrr(t_lst **list_a, t_lst **list_b);
void				pb(t_lst **list_a, t_lst **list_b);
void				pa(t_lst **list_a, t_lst **list_b);
void				ft_push_all_keep_tree(t_lst **stack_a, t_lst **stack_b);
void				ft_make_position(t_lst **stack_a);
void				ft_get_target_postition(t_lst **stack_a, t_lst **stack_b);
int					ft_find_lowest_pos(t_lst **stack_a);
int					ft_find_highest(t_lst *stack_a);
void				ft_get_cost(t_lst **stack_a, t_lst **stack_b);
void				ft_cheapest_move_to_do(t_lst **stack_a, t_lst **stack_b);
void				ft_sort_case_3(t_lst **stack_a);
void				ft_algo(t_lst **stack_a, t_lst **stack_b);
void				ft_move(t_lst **stack_a, t_lst **stack_b, int cost_a,
						int cost_b);
void				ft_do_rotate_b(t_lst **stack_b, int *cost_b);
void				ft_do_rotate_a(t_lst **stack_a, int *cost_a);
void				ft_do_reverse_rotate_both(t_lst **stack_a, t_lst **stack_b,
						int *cost_a, int *cost_b);
void				ft_do_rotate_both(t_lst **stack_a, t_lst **stack_b,
						int *cost_a, int *cost_b);
int					ft_is_sorted(t_lst *stack_a);
int					ft_absolute_value(int nb);
void				ft_set_new_lst(t_lst *new);
void				ft_free_stack(t_lst **stack);
void				ft_exit(t_lst **stack_a, t_lst **stack_b);

#endif
