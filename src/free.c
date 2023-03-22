/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:53:27 by louislaparr       #+#    #+#             */
/*   Updated: 2023/03/22 16:07:06 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_lst **stack)
{
	t_lst	*tmp;

	if (!stack || !(*stack))
		return ;
	while (tmp)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	ft_exit(t_lst **stack_a, t_lst **stack_b)
{
	if (stack_a == NULL || stack_b != NULL)
		ft_free_stack(stack_a);
	if (stack_a != NULL || stack_b == NULL)
		ft_free_stack(stack_b);
	ft_printf("error\n");
	exit (0);
}
