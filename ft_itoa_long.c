/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:39:09 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/30 17:35:18 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	ft_count_for_ten_m(long long int n)
{
	long int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa_long(long long int n)
{
	long int		i;
	int				j;
	unsigned long long	nb;
	char			*str;

	j = 1;
	nb = n;
	i = ft_count_for_ten_m(n);
	str = (char *)ft_memalloc(i + 3);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		nb = -n;
		str[0] = '-';
		j = 0;
	}
	while (i > 0)
	{
		str[i-- - j] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}
