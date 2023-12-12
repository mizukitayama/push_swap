/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:41:59 by mtayama           #+#    #+#             */
/*   Updated: 2023/12/08 19:42:00 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			words++;
		i++;
	}
	return (words);
}

static size_t	count_strlen(char const *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static void	free_arr(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free((void *)strs[i]);
		i++;
	}
	free((void **)strs);
}

static char	**append_arr(char const *s, char c, char **splitted, size_t	words)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] == c)
			i++;
		len = count_strlen(s, c, i);
		splitted[j] = ft_substr(s, (unsigned int)i, len);
		if (splitted[j] == NULL)
		{
			free_arr(splitted);
			return (NULL);
		}
		while (s[i] != c && s[i] != '\0')
			i++;
		j++;
	}
	splitted[j] = NULL;
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char		**splitted;
	size_t		words;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	splitted = (char **)malloc(sizeof(char *) * (words + 1));
	if (splitted == NULL)
		return (NULL);
	splitted = append_arr(s, c, splitted, words);
	return (splitted);
}
