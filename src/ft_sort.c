/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:53:40 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/17 16:58:25 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_lst **list_a)
{
	t_lst	*tmp_1;
	t_lst	*tmp_2;
	t_lst	*tmp_3;

	if ((*list_a)->next == NULL)
		return ;
	tmp_1 = *list_a;
	tmp_2 = tmp_1->next;
	tmp_3 = tmp_2->next;

	tmp_1->next = tmp_3;
	tmp_2->next = tmp_1;
	*list_a = tmp_2;
}

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
	// tmp->next = NULL;
}

void	rra(t_lst **list_a)
{
	t_lst	*new_last;
	t_lst	*new_first;

	new_last = *list_a;
	new_first = *list_a;
	if ((*list_a)->next == NULL)
		return ;
	while (new_last->next)
		new_last = new_last->next;
	new_first = ft_last_lst(*list_a);
	new_last->next = NULL;
	new_first->next = *list_a;
	*list_a = (*list_a)->next;
}
