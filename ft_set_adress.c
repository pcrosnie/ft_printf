/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 10:36:19 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/07/06 15:48:27 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_set_adress(t_arg *arg)
{
	char	*str;
	char	*tmp;

	str = NULL;
	if (!(arg->arg))
	{
		arg->result = "0x";
		return (0);
	}
	else
		str = ft_itoa_base((intmax_t)arg->arg, 16);
	(arg->option[0] == 1) ? str = ft_strjoin("0x", str) : 0;
	 (arg->width >= (int)ft_strlen(str)) ? tmp = ft_memset(ft_strnew(arg->width - ft_strlen(str)), ' ', arg->width - ft_strlen(str)) : 0;
	 (arg->width < (int)ft_strlen(str)) ? tmp = "" : 0;
	 if (arg->option[0] == 0 && arg->width >= (int)ft_strlen(str))
	 {
	 	tmp[ft_strlen(tmp) - 2] = '0';
	 	tmp[ft_strlen(tmp) - 1] = 'x';
	 }
	 else if (arg->option[0] == 0)
		 tmp = "0x";
	if (arg->option[0] == 1)
		arg->result = ft_strjoin(str, tmp);
	else
		arg->result = ft_strjoin(tmp, str);
	return (0);
}
