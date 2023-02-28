/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:17:50 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/27 18:38:55 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_make_stack(int ac, char **av, t_lst **list_a)
{
	int		i;
	char	**args;
	t_lst	*new;

	i = 1;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		i = 0;
	}
	else
		args = av;
	while (args[i])
	{
		new = ft_new_lst(ft_atoi(args[i]));
		ft_add_back_lst(list_a, new);
		if (!(new->content >= INT_MINI &&new->content <= INT_MAXI))
			return (1);
		++i;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_lst	*list_a;
	t_lst	*list_b;
	int		i;

	list_a = NULL;
	list_b = NULL;
	i = 0;
	i = ft_check_all(ac, av);
	if (i != 0)
		return (1);
	i = ft_make_stack(ac, av, &list_a);
	i = ft_check_double(&list_a);
	if (i == 0)
	{
		ft_sort_case_3(&list_a);
		ft_print_stacks(list_a, list_b);
	}
	return (0);
}
