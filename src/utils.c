/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:02:19 by lolaparr          #+#    #+#             */
/*   Updated: 2023/03/10 16:54:25 by louislaparr      ###   ########.fr       */
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

int	ft_size_of_stack(t_lst *stack_a)
{
	int	size;

	size = 0;
	if (stack_a == NULL)
		return (1);
	while (stack_a)
	{
		stack_a = stack_a->next;
		++size;
	}
	return (size);
}

int	ft_absolute_value(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
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
			ft_printf("index : %d ", a_stack->index);
			ft_printf("%d\t\t\t", a_stack->content);
			a_stack = a_stack->next;
		}
		else
			ft_printf("\t\t\t\t\t\t");
		if (b_stack != NULL)
		{
			ft_printf("index : %d ", b_stack->index);
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
