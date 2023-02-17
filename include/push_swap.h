/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:19:10 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/17 15:50:55 by louislaparr      ###   ########.fr       */
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
	void			*next;
}					t_lst;

int					ft_make_stack(int ac, char **av, t_lst **list_a);
t_lst				*ft_new_lst(long long int content);
t_lst				*ft_last_lst(t_lst *lst);
void				ft_add_back_lst(t_lst **lst, t_lst *new);
int					ft_check_all(int ac, char **str);
int					ft_check_len_digit(char **str);
int					ft_check_digit(char **str);
void				sa(t_lst **list_a);
void				ra(t_lst **list_a);
void				rra(t_lst **list_a);

#endif
