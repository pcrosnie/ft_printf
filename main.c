/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:26:11 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/14 17:14:35 by pcrosnie         ###   ########.fr       */
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
	signed char c;
	long long int h;

	h = 123456789110;
	c = '0';
	a = 323;
	d = M_PI;
	str = "dhjakhdjkhsk";
	str2 = "Salut je suis";
	str3 = "le printf qui marche pas encore";
	printf("%-100.10s\n", str3);
	ft_printf("Salut je suis %100.10s heeeeeeeeeeeeeeee", str3);
	return (0);
}
