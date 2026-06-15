#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2) 

{
	size_t	i;
	size_t	j;
	size_t	size_s1;
	size_t	size_s2;
	size_t	total;
	char	*str_cat;

	size_s1 = 0;
	size_s2 = 0;
	i = 0;
	j = 0;

	while (s1[size_s1])
		size_s1++;
	while (s2[size_s2])
		size_s2++;

	total = size_s1 + size_s2;
	str_cat = malloc(total + 1);
	if (str_cat == NULL)
		return (NULL);
	while (s1[i])
	{
		str_cat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str_cat[i] = s2[j];
		i++;
		j++;
	}
	str_cat[i] = '\0';

	return (str_cat);
}
