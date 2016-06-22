/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:26:11 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/22 10:54:43 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

int		main()
{
	char *str;
	char *str2;
	char *str3;
	double d;
	int a;
	signed char s;
	short int c;
	long long int h;
	long x;
	size_t t;

	x = -6378344;
	t = -420;
	h = -9223372036854775807;
	c = 245;
	s = 114;
	a = 323;
	d = M_PI;
	str = "de ouf";
	str2 = "Hello world";
	str3 = "le printf qui marche pas encore";
	printf("%05dsa%%lut%-+15.30llda\n", a, h);
    ft_printf("%05dsa%%lut%-+15.30llda", a, h);
	return (0);
}
