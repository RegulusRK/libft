/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:01:26 by rafcrist          #+#    #+#             */
/*   Updated: 2026/06/17 15:04:08 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;

	if (lst == NULL)
		return ;
	if (del == NULL)
		return ;
	while ((*lst) != NULL)
	{
		next_node = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next_node;
	}
	*lst = NULL;
}
