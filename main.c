/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:26:11 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/21 16:24:30 by pcrosnie         ###   ########.fr       */
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
	intmax_t t;

	t = 420;
	h = -9223372036854775807;
	c = 245;
	s = 114;
	a = 323;
	d = M_PI;
	str = "de ouf";
	str2 = "Hello world";
	str3 = "le printf qui marche pas encore";
	printf("%0.10jdsalut%-+15.30llda\n", t, h);
    ft_printf("%0.10jdsalut%-+15.30llda", t, h);
	return (0);
}
