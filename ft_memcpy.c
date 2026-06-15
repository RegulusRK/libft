#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_c;
	const unsigned char	*src_c;
	size_t				i;
	
	src_c = (const unsigned char *)src;
	dest_c = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		dest_c[i] = src_c[i];
		i++;
	}
	return (dest);
}
