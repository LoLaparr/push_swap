/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:15:16 by lolaparr          #+#    #+#             */
/*   Updated: 2023/03/22 16:57:31 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_lst **list_a, int nb)
{
	t_lst	*new_last;
	t_lst	*new_first;

	if (list_a == NULL || (*list_a)->next == NULL)
		return ;
	new_first = ft_last_lst(*list_a);
	new_last = *list_a;
	while (new_last->next->next)
		new_last = new_last->next;
	new_last->next = NULL;
	new_first->next = *list_a;
	(*list_a) = new_first;
	if (nb == 0)
		ft_printf("rra\n");
}

void	rrb(t_lst **list_b, int nb)
{
	t_lst	*new_last;
	t_lst	*new_first;

	if (list_b == NULL || (*list_b)->next == NULL)
		return ;
	new_first = ft_last_lst(*list_b);
	new_last = *list_b;
	while (new_last->next->next)
		new_last = new_last->next;
	new_last->next = NULL;
	new_first->next = *list_b;
	(*list_b) = new_first;
	if (nb == 0)
		ft_printf("rrb\n");
}

void	rrr(t_lst **list_a, t_lst **list_b)
{
	rra(list_a, 1);
	rrb(list_b, 1);
	ft_printf("rrr\n");
}
