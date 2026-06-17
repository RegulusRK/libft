/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:37:53 by rafcrist          #+#    #+#             */
/*   Updated: 2026/06/17 17:01:25 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str_cat;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str_cat = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	if (str_cat == NULL)
		return (NULL);
	while (s1[i])
	{
		str_cat[i] = s1[i];
		i++;
	}
	while (s2[j])
		str_cat[i++] = s2[j++];
	str_cat[i] = '\0';
	return (str_cat);
}
