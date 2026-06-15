#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*new_str;
	size_t	copy_len;

	i = 0;
	end = 0;
	start = 0;
	while (s1[end])
		end++;
	while (is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;

	copy_len = end - start;
	new_str = malloc(copy_len + 1);
	if (new_str == NULL)
		return (NULL);
	while (i < copy_len)
	{
		new_str[i] = s1[start + i];
		i++;
	}
	new_str[i] = '\0';

	return (new_str);
}
