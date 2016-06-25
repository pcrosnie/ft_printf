/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 10:41:53 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/25 14:13:20 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{
	int a;
	int ret;
	uintmax_t d;

	d = -4294967296;
	a = '\0';
	setlocale(LC_ALL, "");

	printf("%-05d\n", -42);	
	ft_printf("%-05d\n", -42);	
	return (0);
}

