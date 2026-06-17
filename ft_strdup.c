/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:35:05 by rafcrist          #+#    #+#             */
/*   Updated: 2026/06/17 15:35:23 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	s_len;
	char	*mem;

	i = 0;
	s_len = 0;
	while (s[s_len])
		s_len++;
	mem = malloc(s_len + 1);
	if (mem == NULL)
		return (NULL);
	while (i < s_len)
	{
		mem[i] = s[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
