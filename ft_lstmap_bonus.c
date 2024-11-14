/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:21:50 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/10 15:35:05 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_lst;
	t_list	*new_node;
	void	*t;

	if (!f || !del)
		return (NULL);
	new_lst = NULL;
	tmp = lst;
	while (tmp != NULL)
	{
		t = f(tmp->content);
		new_node = ft_lstnew(t);
		if (!new_node)
		{
			del(t);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		tmp = tmp->next;
		ft_lstadd_back(&new_lst, new_node);
	}
	return (new_lst);
}
