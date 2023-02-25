/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:19:10 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/25 18:17:47 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

# define INT_MAXI 2147483648
# define INT_MINI -2147483647

typedef struct s_lst
{
	long long int	content;
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
void				sa(t_lst **list_a);
void				sb(t_lst **list_b);
void				ss(t_lst **list_a, t_lst **list_b);
void				ra(t_lst **list_a);
void				rb(t_lst **list_b);
void				rr(t_lst **list_a, t_lst **list_b);
void				rra(t_lst **list_a);
void				rrb(t_lst **list_b);
void				rrr(t_lst **list_a, t_lst **list_b);
void				ft_print_stacks(t_lst *stack_a, t_lst *stack_b);
void				pb(t_lst **list_a, t_lst **list_b);
void				pa(t_lst **list_a, t_lst **list_b);

#endif
