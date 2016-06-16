/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:26:11 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/16 14:54:17 by pcrosnie         ###   ########.fr       */
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
	signed char c;
	long long int h;

	h = 123456789110;
	c = '6';
	s = 'r';
	a = 323;
	d = M_PI;
	str = "de ouf";
	str2 = "Hello world";
	str3 = "le printf qui marche pas encore";
	printf("%-10hhdsalut%+010.4hhd\n", c, s);
    ft_printf("%-10hhdsalut%+010.4hhd", c, s);
	return (0);
}
