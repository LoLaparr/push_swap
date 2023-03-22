/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:17:50 by lolaparr          #+#    #+#             */
/*   Updated: 2023/03/21 14:43:50 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_lst *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content > stack_a->next->content)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	ft_make_stack(int ac, char **av, t_lst **list_a)
{
	int		i;
	long long int	nb;
	char	**args;
	t_lst	*new;

	i = 1;
	nb = 0;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		i = 0;
	}
	else
		args = av;
	while (args[i])
	{
		nb = ft_atoi(args[i]);
		if (nb > INT_MAXI || nb < INT_MINI)
			return (1);
		new = ft_new_lst(nb);
		ft_set_new_lst(new);
		ft_add_back_lst(list_a, new);
		++i;
	}
	return (0);
}

void	ft_do_index(t_lst *stack_a, int stack_size)
{
	int	content;
	t_lst *highest;
	t_lst *tmp;

	while (stack_size > 0)
	{
		content = INT_MINI;
		tmp = stack_a;
		highest = NULL;
		while (tmp)
		{
			if (tmp->content == INT_MINI && tmp->index == 0)
				tmp->index = 1;
			if (tmp->content > content && tmp->index == 0)
			{
				content = tmp->content;
				highest = tmp;
				tmp = stack_a;
			}
			else
				tmp = tmp->next;
		}
		--stack_size;
		if (highest != NULL)
			highest->index = stack_size;
	}
}

int	main(int ac, char **av)
{
	t_lst	*list_a;
	t_lst	*list_b;
	int		i;
	int		size;

	list_a = NULL;
	list_b = NULL;
	i = 0;
	i = ft_check_all(ac, av);
	if (i != 0)
		return (1);
	i = ft_make_stack(ac, av, &list_a);
	i = ft_check_double(&list_a);
	size = ft_size_of_stack(list_a);
	ft_do_index(list_a, size + 1);
	if (i == 0)
	{
		ft_print_stacks(list_a, list_b);
		ft_algo(&list_a, &list_b);
		ft_print_stacks(list_a, list_b);
	}
	return (0);
}
