/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:17:50 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/17 16:58:44 by louislaparr      ###   ########.fr       */
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
		if (!(new->content >= INT_MINI && new->content <= INT_MAXI))
			return (1);
		++i;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_lst	*list_a;
	t_lst	*cpy;
	int		i;

	list_a = NULL;
	i = 0;
	i = ft_check_all(ac, av);
	if (i != 0)
		return (1);
	i = ft_make_stack(ac, av, &list_a);
	 cpy = list_a;
	 while (cpy)
	 {
	 	ft_printf("\ncontent : %i\n", cpy->content);
	 	cpy = cpy->next;
	 }
	 sa(&list_a);
	 ft_printf("----------------");
	 while (list_a)
	 {
	 	ft_printf("\ncontent : %i\n", list_a->content);
	 	list_a = list_a->next;
	 }
	return (0);
}
