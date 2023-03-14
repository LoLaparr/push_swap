/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:30:01 by louislaparr       #+#    #+#             */
/*   Updated: 2023/03/14 17:39:28 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_rotate_both(t_lst **stack_a, t_lst **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		--(*cost_a);
		--(*cost_b);
		rr(stack_a, stack_b);
	}
}

void	ft_do_reverse_rotate_both(t_lst **stack_a, t_lst **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		++(*cost_a);
		++(*cost_b);
		rrr(stack_a, stack_b);
	}
}

void	ft_do_rotate_a(t_lst **stack_a, int *cost_a)
{
	if (*cost_a > 0)
	{
		while (*cost_a > 0)
		{
			--(*cost_a);
			ra(stack_a);
		}
	}
	else if (*cost_a < 0)
	{
		while (*cost_a < 0)
		{
			++(*cost_a);
			rra(stack_a);
		}
	}
}

void	ft_do_rotate_b(t_lst **stack_b, int *cost_b)
{
	if (*cost_b > 0)
	{
		while (*cost_b > 0)
		{
			--(*cost_b);
			rb(stack_b);
		}
	}
	else if (*cost_b < 0)
	{
		while (*cost_b < 0)
		{
			++(*cost_b);
			rrb(stack_b);
		}
	}
}

void	ft_move(t_lst **stack_a, t_lst **stack_b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		ft_do_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		ft_do_reverse_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	ft_do_rotate_a(stack_a, &cost_a);
	ft_do_rotate_b(stack_b, &cost_b);
	pa(stack_a, stack_b);
}
