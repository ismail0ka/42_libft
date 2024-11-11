/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:25:17 by ikarouat          #+#    #+#             */
/*   Updated: 2024/10/27 22:57:47 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	if (!src || !dst || len == 0)
		return (dst);
	tmp_d = dst;
	tmp_s = (unsigned char *) src;
	if (src < dst)
	{
		while (len > 0)
		{
			len--;
			*(tmp_d + len) = *(tmp_s + len);
		}
	}
	else if (src > dst)
	{
		while (len > 0)
		{
			*(tmp_d++) = *(tmp_s++);
			len--;
		}
	}
	return (dst);
}