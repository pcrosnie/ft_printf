/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 10:57:33 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/23 11:50:54 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wchar(t_arg *arg)
{
	wchar_t n;
	char	*str;

	str = NULL;
	n = (wchar_t)arg->arg;
	(n <= 127) ? str = ft_mask1(n) : 0;
	(n > 127 && n <= 2047) ? str = ft_mask2(n) : 0 ;
	(n > 2047 && n <= 65535) ? str = ft_mask3(n) : 0;
	(n > 65535) ? str = ft_mask3(n) : 0;
	arg->result = ft_strdup(str);
	free(str);
	return(0);
}
