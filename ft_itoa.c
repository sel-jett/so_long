/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:38:27 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/06 00:53:58 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count(long long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	if (n >= 0 && n <= 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*my_func(char *str, long long nb, int mal)
{
	str[mal--] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	while (nb > 9)
	{
		str[mal--] = ((nb % 10) + 48);
		nb /= 10;
	}
	if (nb >= 0 && nb <= 9)
	{
		str[mal--] = ((nb % 10) + 48);
		nb /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long long	nb;
	char		*str;
	int			mal;

	nb = (long long)n;
	mal = ft_count(nb);
	str = my_malloc((sizeof(char) * mal + 1), 1);
	str = my_func(str, nb, mal);
	return (str);
}
