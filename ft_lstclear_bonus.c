/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:45:12 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/10 15:32:24 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*to_free;

	if (!lst || !del)
		return ;
	to_free = *lst;
	while (to_free != NULL)
	{
		tmp = to_free->next;
		ft_lstdelone(to_free, del);
		to_free = tmp;
	}
	*lst = NULL;
}
