/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:00:24 by lolaparr          #+#    #+#             */
/*   Updated: 2023/03/27 15:21:33 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_lst **list_a, int nb)
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
	if (nb == 0)
		ft_printf("sa\n");
}

void	sb(t_lst **list_b, int nb)
{
	t_lst	*tmp_1;
	t_lst	*tmp_2;
	t_lst	*tmp_3;

	if ((*list_b)->next == NULL)
		return ;
	tmp_1 = *list_b;
	tmp_2 = tmp_1->next;
	tmp_3 = tmp_2->next;
	tmp_1->next = tmp_3;
	tmp_2->next = tmp_1;
	*list_b = tmp_2;
	if (nb == 0)
		ft_printf("sb\n");
}

void	ss(t_lst **list_a, t_lst **list_b)
{
	sa(list_a, 1);
	sb(list_b, 1);
	ft_printf("ss\n");
}
