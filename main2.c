/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 15:19:33 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/13 11:56:57 by pcrosnie         ###   ########.fr       */
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
	flags[2] = "0";
//	flags[4] = "#";
	flags[0] = "-";
	flags[1] = "+";
	flags[3] = " ";
	arg = "arg";
	str = (char *)malloc(sizeof(char) * 100);
	while (i < 4)
	{
	precision = 0;
	while (precision < 20)
	{
		width = 0;
		while (width < 20)
		{
				nb++;
				str = ft_strjoin_nf("%", flags[i], 0);
				if (width != 0)
				str = ft_strjoin_nf(str, ft_itoa(width), 3);
				str = ft_strjoin_nf(str, ".", 1);
				str = ft_strjoin_nf(str, ft_itoa(precision), 3);
				str = ft_strjoin_nf(str, "d", 1);
				str = ft_strjoin_nf(str, "\n", 1);
//				ft_putstr(str);
//				ft_putchar('\n');
//				ft_putstr("printf :");*/
//				printf(str, -1);
//				ft_putstr("ft_printf :");
				ft_printf(str, -1);
				free(str);
			width++;
		}
		precision++;
	}
	i++;
	}
	return (0);
}

