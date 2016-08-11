/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 15:19:33 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/11 12:13:07 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *str;
	char **flags;
	char *arg;
	int  precision;
	int width;
	int i;
	int nb;

	i = 0;
	nb = 0;
	precision = 0;
	width = 0;
	flags = (char **)malloc(sizeof(char *) * 6);
//	flags[0] = "0";
//	flags[4] = "#";
	flags[0] = "-";
//	flags[1] = "+";
//	flags[3] = " ";
	arg = "arg";
	str = (char *)malloc(sizeof(char) * 100);
	precision = 0;
	while (precision < 20)
	{
		width = 0;
		while (width < 20)
		{
			i = 0;
			while (i < 1)
			{
				nb++;
				str = ft_memset(str, '\0', 50);
				str = ft_strjoin_nf("%", flags[i], 0);
				if (width != 0)
				str = ft_strjoin_nf(ft_strdup(str), ft_itoa(width), 3);
				str = ft_strjoin_nf(ft_strdup(str), ".", 1);
				str = ft_strjoin_nf(ft_strdup(str), ft_itoa(precision), 3);
				str = ft_strjoin_nf(ft_strdup(str), "p", 1);
				printf(str, arg);
				ft_putchar('\n');
				ft_printf(str, arg);
				ft_putchar('\n');
				ft_putstr(str);
				ft_putchar('\n');
				i++;
			}
			width++;
		}
		precision++;
	}
	ft_putnbr(nb);
	return (0);
}

