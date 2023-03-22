/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:11:23 by louislaparr       #+#    #+#             */
/*   Updated: 2023/03/22 15:42:28 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_in_order(t_lst **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	lowest_pos = ft_find_lowest_pos(stack_a);
	stack_size = ft_size_of_stack(*stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			ft_printf("JE PASSE");
			rra(stack_a);
			++lowest_pos;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			--lowest_pos;
		}
	}
}

void	ft_push_all_keep_tree(t_lst **stack_a, t_lst **stack_b)
{
	int	i;
	int	pushed;
	int	stack_size;

	i = 0;
	pushed = 0;
	stack_size = ft_size_of_stack(*stack_a);
	while (stack_size > 6 && i < stack_size && pushed < (stack_size / 2))
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			++pushed;
		}
		else
			ra(stack_a);
		++i;
	}
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b);
		++pushed;
	}
}

void	ft_algo(t_lst **stack_a, t_lst **stack_b)
{
	int	i;

	ft_push_all_keep_tree(stack_a, stack_b);
	ft_sort_case_3(stack_a);
	while (*stack_b)
	{
		ft_get_target_postition(stack_a, stack_b);
		ft_get_cost(stack_a, stack_b);
		ft_cheapest_move_to_do(stack_a, stack_b);
	}
	i = ft_is_sorted(*stack_a);
	if (i > 0)
		ft_put_in_order(stack_a);

}
