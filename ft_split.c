/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:25:01 by rafcrist          #+#    #+#             */
/*   Updated: 2026/06/17 15:34:14 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			word++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (word);
}

static char	*copy_word(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	*new_word;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	new_word = malloc(len + 1);
	if (new_word == NULL)
		return (NULL);
	while (i < len)
	{
		new_word[i] = s[i];
		i++;
	}
	new_word[i] = '\0';
	return (new_word);
}

static char	**free_split(char **split, size_t j)
{
	while (j > 0)
	{
		j--;
		free(split[j]);
	}
	free(split);
	return (NULL);
}

static char	**fill_split(char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			split[j] = copy_word(&s[i], c);
			if (split[j] == NULL)
				return (free_split(split, j));
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (s == NULL)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	return (fill_split(split, s, c));
}
