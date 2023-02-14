/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:02:19 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/10 13:40:54 by lolaparr         ###   ########.fr       */
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
