/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:02:19 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/28 17:43:21 by lolaparr         ###   ########.fr       */
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

void	ft_print_stacks(t_lst *a_stack, t_lst *b_stack)
{
	ft_printf("-------------------");
	ft_printf("-------------------\t\t\t\n\n");
	ft_printf("a_stack\t\t\tb_stack\n");
	while (a_stack != NULL || b_stack != NULL)
	{
		if (a_stack != NULL)
		{
			ft_printf("%d\t\t\t", a_stack->content);
			a_stack = a_stack->next;
		}
		else
			ft_printf("\t\t\t\t\t\t");
		if (b_stack != NULL)
		{
			ft_printf("%d\t\t\t", b_stack->content);
			b_stack = b_stack->next;
		}
		else
			ft_printf("\t\t\t\t\t\t");
		ft_printf("\n");
	}
	ft_printf("-------------------");
	ft_printf("-------------------\t\t\t\n\n");
}
