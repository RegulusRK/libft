#include "libft.h"

static	size_t	count_digits(long n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	max;
	char 	*num_str;
	long	nb;

	nb = n;
	max = count_digits(nb);
	num_str = malloc(max + 1);
	if (num_str == NULL)
		return (NULL);
	if (nb == 0)
		num_str[0] = '0';
	if (nb < 0)
	{
		num_str[0] = '-';
		nb = -nb;
	}
	num_str[max] = '\0';
	while (nb > 0)
	{
		max--;
		num_str[max] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (num_str);
}
