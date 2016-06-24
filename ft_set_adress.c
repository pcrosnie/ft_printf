/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 10:36:19 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/24 11:46:48 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_set_adress(t_arg *arg)
{
	char	*str;
	char	*tmp;

	if (!(arg->arg))
		str = "0x0";
//	else
//		str = ft_ull_base((unsigned long long)&arg->arg, 16);
	 (arg->width >= ft_strlen(str)) ? tmp = ft_memset(ft_strnew(arg->width - ft_strlen(str)), ' ', arg->width - ft_strlen(str)) : 0;
	 (arg->width < ft_strlen(str)) ? tmp = "" : 0;
//	 tmp[ft_strlen(tmp) - 2] = '0';
//	 tmp[ft_strlen(tmp) - 1] = 'x';
	if (arg->option[0] == 1)
		arg->result = ft_strjoin(str, tmp);
	else
		arg->result = ft_strjoin(tmp, str);
	return (0);
}
/*
int		ft_set_adress(t_arg *arg)
{
	char	*str;
	char	*tmp;

	str = (char *)malloc(sizeof(arg->arg));
	str = ft_memcpy(str, &arg->arg, sizeof(arg->arg));
	tmp = ft_itoa_base(str[1], 16);
	ft_putstr(tmp);
	return (0);
}*/
