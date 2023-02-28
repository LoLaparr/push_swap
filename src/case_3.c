/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:13:16 by louislaparr       #+#    #+#             */
/*   Updated: 2023/02/28 16:23:27 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_highest(t_lst *stack_a)
{
	int	highest;

	highest = stack_a->content;
	while (stack_a)
	{
		if (highest < stack_a->content)
			highest = stack_a->content;
		stack_a = stack_a->next;
		ft_printf("highest %i\n", highest);
	}
	return (highest);
}

void	ft_sort_case_3(t_lst **stack_a)
{
	int	highest;

	highest = ft_find_highest((*stack_a));
	if (highest == (*stack_a)->content)
		ra(stack_a);
	else if (highest == (*stack_a)->next->content)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}
