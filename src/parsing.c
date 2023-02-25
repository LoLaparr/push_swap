/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:20:32 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/25 17:43:22 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_digit(char **str)
{
	int	i;
	int	j;

	j = 1;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (ft_isdigit(str[j][i]) == 1)
				return (1);
			++i;
		}
		++j;
	}
	return (0);
}

int	ft_check_len_digit(char **str)
{
	int	i;
	int	j;

	j = 1;
	while (str[j])
	{
		i = (int)ft_strlen(str[j]);
		if (str[j][0] == '-' && i > 11)
			return (1);
		if (str[j][0] != '-' && i > 10)
			return (1);
		++j;
	}
	return (0);
}

int	ft_check_all(int ac, char **str)
{
	int		i;
	char	**args;

	i = 0;
	args = NULL;
	if (ac == 2)
		args = ft_split(str[1], ' ');
	else
		args = str;
	i += ft_check_digit(args);
	i += ft_check_len_digit(args);
	return (i);
}

int	ft_check_double(t_lst **stack_a)
{
	t_lst	*cpy;
	t_lst	*tmp;
	int		i;
	int		j;

	tmp = (*stack_a);
	i = 0;
	while (tmp)
	{
		cpy = (*stack_a);
		j = 0;
		while (cpy)
		{
			if (i != j)
				if (cpy->content == tmp->content)
					return (1);
			cpy = cpy->next;
			++j;
		}
		++i;
		tmp = tmp->next;
	}
	return (0);
}
