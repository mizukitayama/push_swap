/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:42:01 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/26 07:27:09 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*copy_slice(char *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[(size_t)start + i] && i < len)
		i++;
	if (i == 0)
		return (NULL);
	t = (char *)malloc(sizeof(char) * (i + 1));
	if (t == NULL)
		return (NULL);
	while (i > j)
	{
		t[j] = s[j + (size_t)start];
		j++;
	}
	t[j] = '\0';
	return (t);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*t;

	if (len == 0 || !s || (size_t)start >= ft_strlen(s))
	{
		t = (char *)malloc(sizeof(char) * 1);
		if (t == NULL)
			return (NULL);
		t[0] = '\0';
		return (t);
	}
	else
	{
		return (copy_slice(s, start, len));
	}
}
