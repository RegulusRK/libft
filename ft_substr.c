#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	size_t size;
	char *sub_s;
	size_t copy_len;

	size = 0;
	i = 0;
	while (s[size])
		size++;	
	if (start >= size)
	{
		sub_s = malloc(1);
		if (sub_s == NULL)
			return (NULL);
		sub_s[0] = '\0';
		return (sub_s);
	}
	if (len < size - start)
		copy_len = len;
	else
		copy_len = size - start;
	sub_s = malloc(copy_len + 1);
	if (sub_s == NULL)
		return (NULL);
	while (i < copy_len && s[start + i])
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';

	return (sub_s);
}
