/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:26:11 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/23 15:09:03 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

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
	wchar_t *w;
	char u;

	u = 'a';
	setlocale(LC_ALL, "");
	w = (wchar_t *)malloc(sizeof(wchar_t) * 10);
	*w = 2345;;
	//w[1] = '\0';
	t = 2345;
	x = -6378344;
	t = -420;
	h = -9223372036854775807;
	c = 245;
	s = 114;
	a = 2217398;
//	d = M_PI;
	str = "de ouf";
	str2 = "Hello world";
	str3 = "le printf qui marche pas encore";
	printf("%-10c\n", u);
	ft_printf("%-10c\n", u);
	return (0);
}
