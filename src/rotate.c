/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:09:21 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/25 18:12:44 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_lst **list_a)
{
	t_lst	*tmp;
	t_lst	*tmp_2;

	if ((*list_a)->next == NULL)
		return ;
	tmp_2 = *list_a;
	tmp = ft_last_lst(*list_a);
	tmp->next = *list_a;
	*list_a = (*list_a)->next;
	tmp_2->next = NULL;
}

void	rb(t_lst **list_b)
{
	t_lst	*tmp;
	t_lst	*tmp_2;

	if ((*list_b)->next == NULL)
		return ;
	tmp_2 = *list_b;
	tmp = ft_last_lst(*list_b);
	tmp->next = *list_b;
	*list_b = (*list_b)->next;
	tmp_2->next = NULL;
}

void	rr(t_lst **list_a, t_lst **list_b)
{
	ra(list_a);
	rb(list_b);
}
