/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:39:05 by louislaparr       #+#    #+#             */
/*   Updated: 2023/03/10 16:57:51 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_cost(t_lst **stack_a, t_lst **stack_b)
{
	int	size_a;
	int	size_b;
	t_lst	*tmp_a;
	t_lst	*tmp_b;

	size_a = ft_size_of_stack(*stack_a);
	size_b = ft_size_of_stack(*stack_b);
	tmp_a = *stack_a;
	tmp_b = *size_b;
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->cost_b > (size_b / 2))
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->pos_target;
		if (tmp_b->pos_target > (size_a / 2))
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
		if (ft_absolute_value(cost_a) + ft_absolute_value(cost_b) < ft_absolute_value(cheapest))
		{
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
			cheapest = ft_absolute_value(cost_a) + ft_absolute_value(cost_b);
		}
		tmp = tmp->next;
	}
	ft_move(stack_a, size_b, cost_a, cost_b);
}
