/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 15:05:39 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/11 11:43:46 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define D "%d"

int		main(void)
{

	printf("%1.2s", "arg");
	ft_printf("%1.2s", "arg");
	return (0);
}