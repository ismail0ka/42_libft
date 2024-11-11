/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:17:50 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/03 14:48:38 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_b;

	if (!b)
		return (b);
	tmp_b = b;
	while (len > 0)
	{
		*((unsigned char *) tmp_b++) = (unsigned char) c;
		len--;
	}
	return (b);
}