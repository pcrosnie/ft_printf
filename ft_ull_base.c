/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 11:39:12 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/07/28 14:31:09 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	ft_count_base_m(unsigned long long n, int base)
{
	long int	i;

	i = 0;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		ft_set_bases(int n)
{
	char c;

	if (ft_isdigit(n) == 1)
		c = (char)n;
	else
		c = n + 39;
	return (c);
}

char		*ft_ull_base(unsigned long long n, int base)
{
	long int			i;
	int					j;
	unsigned long long	nb;
	char				*str;

	j = 1;
	nb = n;
	i = ft_count_base_m(n, base) + 1;
	str = (char *)ft_memalloc(i + 3);
	if (n == 0)
		str[0] = '0';
	while (i > 0)
	{
		str[i-- - 2] = ft_set_bases((nb % base) + 48);
		nb = nb / base;
	}
	return (str);
}
