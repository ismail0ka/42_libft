/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:03:32 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/12 16:47:03 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	free_chunks(char **strs, unsigned int exist)
{
	unsigned int	i;

	i = 0;
	while (i < exist)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static unsigned int	word_count(const char *s, int c)
{
	unsigned int	count_w;

	count_w = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count_w++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (count_w);
}

static unsigned int	next_delimiter(const char *s, int c)
{
	unsigned int	count;

	count = 0;
	while (*(s + count) != c && *(s + count) != '\0')
		count++;
	return (count);
}

static char	*get_next_word(char **strs, const char **s
	, int c, unsigned int exist)
{
	char			*chunk;
	unsigned int	del;
	unsigned int	i;

	i = 0;
	while (**s == c)
		(*s)++;
	del = next_delimiter(*s, c);
	chunk = (char *)malloc(del + 1);
	if (!chunk)
	{
		free_chunks(strs, exist);
		return (NULL);
	}
	while (i < del)
		chunk[i++] = *((*s)++);
	chunk[i] = '\0';
	return (chunk);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	char			*chunk;
	unsigned int	i;
	unsigned int	res_len;

	if (!s)
		return (NULL);
	res_len = word_count(s, c);
	res = (char **)malloc((res_len + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s && i < res_len)
	{
		chunk = get_next_word(res, &s, c, i);
		if (!chunk)
			return (NULL);
		else
			res[i++] = chunk;
	}
	res[res_len] = NULL;
	return (res);
}
