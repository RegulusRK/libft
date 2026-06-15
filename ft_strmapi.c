#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int i;
	size_t	size_s;
	char *str_m;

	i = 0;
	size_s = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while(s[size_s])
		size_s++;

	str_m = malloc(size_s + 1);
	if (str_m == NULL)
		return (NULL);
	while (s[i])
	{
		str_m[i] = f(i, s[i]);
		i++;
	}
	str_m[i] = '\0';

	return (str_m);
}
