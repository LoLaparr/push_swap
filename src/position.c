/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:13:07 by louislaparr       #+#    #+#             */
/*   Updated: 2023/03/22 16:26:47 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_position(t_lst **stack_a)
{
	int	i;
	t_lst	*tmp;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		++i;
	}
}

int	ft_find_lowest_pos(t_lst **stack_a)
{
	int	lowest_pos;
	int	lowest_index;
	t_lst	*tmp;

	ft_make_position(stack_a);
	tmp = *stack_a;
	lowest_pos = tmp->pos;
	lowest_index = INT_MAXI;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

int	ft_get_target(t_lst **stack_a, int index_b, int index_target, int pos_target)
{
	t_lst	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < index_target)
		{
			index_target = tmp->index;
			pos_target = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (index_target != INT_MAXI)
		return (pos_target);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < index_target)
		{
			index_target = tmp->index;
			pos_target = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (pos_target);
}

void	ft_get_target_postition(t_lst **stack_a, t_lst **stack_b)
{
	int	target_pos;
	t_lst	*tmp;

	tmp = *stack_b;
	ft_make_position(stack_a);
	ft_make_position(stack_b);
	target_pos = 0;
	while (tmp)
	{
		target_pos = ft_get_target(stack_a, tmp->index, INT_MAXI, target_pos);
		tmp->pos_target = target_pos;
		tmp = tmp->next;
	}
}
