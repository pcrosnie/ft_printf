/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 14:52:00 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/25 13:07:17 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_set_char(t_arg *arg)
{
	char *str;
	char *tmp;

//	if (arg->arg == 0)
//	{
//		arg->result = "\0";
//		return (0);
//	}
	str = ft_strnew(1);
	str[0] = (int)arg->arg;
	str[1] = '\0';
	(arg->width >= 1) ? tmp = ft_memset(ft_strnew(arg->width - 1), ' ', arg->width - 1) : 0;
	(arg->width < 1) ? tmp = "" : 0;
	if (arg->option[0] == 1)
		arg->result = ft_strjoin(str, tmp);
	else
		arg->result = ft_strjoin(tmp, str);
	free(str);
	return (0);
}
