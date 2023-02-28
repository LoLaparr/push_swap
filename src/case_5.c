/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:37:36 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/28 18:06:59 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len_of_stack(t_lst *stack_a)
{
	int	len;

	len = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		++len;
	}
	return (len);
}

int	ft_is_sort(t_lst *stack_a)
{
	t_lst	*tmp;

	tmp = stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_sort_case_5(t_lst **stack_a, t_lst **stack_b)
{
	int	len;

	len = ft_len_of_stack((*stack_a));
	while (len > 3)
	{
		pb(stack_a, stack_b);
		len = ft_len_of_stack((*stack_a));
	}
	ft_sort_case_3(stack_a);
	ft_sort_case_3(stack_b);
	ft_print_stacks(*stack_a, *stack_b);
	while (*stack_b != NULL)
	{
		if ((*stack_a)->content > (*stack_b)->content)
			pa(stack_a, stack_b);
		else
			ra(stack_a);
	}
	while (ft_is_sort(*stack_a) == 1)
		ra(stack_a);
}
