/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:24:20 by rafcrist          #+#    #+#             */
/*   Updated: 2026/06/17 15:24:33 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nu;
	char			result;

	nu = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nu = -nu;
	}
	if (nu > 9)
	{
		ft_putnbr_fd(nu / 10, fd);
	}
	result = (nu % 10) + '0';
	write(fd, &result, 1);
}
