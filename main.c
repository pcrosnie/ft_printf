/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 10:41:53 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/30 14:37:12 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>

int main(void)
{
	int a;
	int ret;
	uintmax_t d;
	size_t t;

	t = LLONG_MIN;
	d = -4294967296;
	a = '\0';
	setlocale(LC_ALL, "");

	ret = printf("%#o", 0);
	ft_putchar('\n');
	ft_putnbr(ret);
	ft_putchar('\n');
	ret = ft_printf("%#o", 0);
	ft_putchar('\n');
	ft_putnbr(ret);
	ft_putchar('\n');
	return (0);
}

