#include "libft.h"

char	*ft_strchr(const char *s, int c)
{ 
	size_t	i;

	i = 0;
	while (s[i] != (char)c && s[i])
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
