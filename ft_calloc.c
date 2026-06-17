/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:05:26 by rafcrist          #+#    #+#             */
/*   Updated: 2026/06/17 14:05:49 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*cal;
	size_t			tt;

	if (size != 0 && nmemb > ((size_t)-1) / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	tt = (size * nmemb);
	i = 0;
	cal = malloc(tt);
	if (cal == NULL)
		return (NULL);
	while (i < tt)
	{
		cal[i] = '\0';
		i++;
	}
	return (cal);
}
