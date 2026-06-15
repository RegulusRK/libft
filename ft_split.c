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

static size_t	word_len(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char	*copy_word(char const *s, char c)
{
	size_t	i;
	char	*new_word;
	size_t	len;

	i = 0;
	len = word_len(s, c);
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

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	words;
	char	**split;

	i = 0;
	j = 0;
	words = (count_words(s, c));
	split = malloc((words + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
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
