/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:51:21 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/25 18:02:02 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_lst **list_a, t_lst **list_b)
{
	t_lst	*tmp;

	if ((*list_a) == NULL)
		return ;
	tmp = (*list_a)->next;
	(*list_a)->next = *list_b;
	*list_b = *list_a;
	*list_a = tmp;
}

void	pa(t_lst **list_a, t_lst **list_b)
{
	t_lst	*tmp;

	if ((*list_b) == NULL)
		return ;
	tmp = (*list_b)->next;
	(*list_b)->next = *list_a;
	*list_a = *list_b;
	*list_b = tmp;
}
