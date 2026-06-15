#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;
	size_t	dst_end;

	dst_len = 0;
	src_len = 0;
	
	while (src[src_len])
		src_len++;
	while (dst_len < size && dst[dst_len])
		dst_len++;

	if (size == 0)
		return (src_len);
	if (dst_len >= size)
		return (src_len + size);

	i = 0;
	dst_end = dst_len;
	while (i < (size - dst_len) - 1 && src[i])
	{
		dst[dst_end] = src[i];
		i++;
		dst_end++;
	}
	dst[dst_end] = '\0';

	return (dst_len + src_len);
}
