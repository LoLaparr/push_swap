/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:39:05 by louislaparr       #+#    #+#             */
/*   Updated: 2023/03/19 15:37:18 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_cost(t_lst **stack_a, t_lst **stack_b)
{
	int	size_a;
	int	size_b;
	t_lst	*tmp_a;
	t_lst	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_size_of_stack(tmp_a);
	size_b = ft_size_of_stack(tmp_b);
	printf("tmp_b->cost_b : %i\ntmp_b->pos : %i\n", tmp_b->cost_b, tmp_b->pos);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->pos_target;
		if (tmp_b->pos_target > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->pos_target) * -1;
		tmp_b = tmp_b->next;
	}
}

void	ft_cheapest_move_to_do(t_lst **stack_a, t_lst **stack_b)
{
	int	cost_a;
	int	cost_b;
	int	cheapest;
	t_lst	*tmp;

	cheapest = INT_MAXI;
	tmp = *stack_b;
	while (tmp)
	{
		if (ft_absolute_value(tmp->cost_a) + ft_absolute_value(tmp->cost_b) < ft_absolute_value(cheapest))
		{
			cheapest = ft_absolute_value(tmp->cost_a) + ft_absolute_value(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
			printf("tmp->cost a : %i\n", tmp->cost_a);
		}
		tmp = tmp->next;
	}
	ft_move(stack_a, stack_b, cost_a, cost_b);
}
