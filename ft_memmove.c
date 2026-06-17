/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:22:27 by rafcrist          #+#    #+#             */
/*   Updated: 2026/06/17 15:23:00 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_c;
	const unsigned char	*src_c;
	size_t				i;

	src_c = (const unsigned char *)src;
	dest_c = (unsigned char *)dest;
	i = 0;
	if (src_c > dest_c)
	{
		while (i < n)
		{
			dest_c[i] = src_c[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			dest_c[n - 1] = src_c[n - 1];
			n--;
		}
	}
	return (dest);
}
