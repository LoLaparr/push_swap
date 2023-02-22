/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:02:19 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/22 15:55:26 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_back_lst(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (lst == NULL || new == NULL)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	else
	{
		tmp = ft_last_lst(*lst);
		tmp->next = new;
	}
}

t_lst	*ft_last_lst(t_lst *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_lst	*ft_new_lst(long long int content)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_print_stacks(t_lst *stack_a, t_lst *stack_b)
{
	ft_printf("\n---------------------\t");
	ft_printf("\t---------------------\n");
	while (stack_a || stack_b)
	{
		if (stack_a != NULL)
		{
			ft_printf("content stack_a : %i",
						stack_a->content);
			stack_a = stack_a->next;
			ft_printf("\t\t");
		}
		if (stack_b != NULL)
		{
			ft_printf("content stack_b : %i\n", stack_b->content);
			stack_b = stack_b->next;
		}
	}
		ft_printf("\n---------------------\t");
		ft_printf("\t---------------------\n");
}
