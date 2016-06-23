/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 10:57:33 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/23 13:09:35 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wchar(t_arg *arg)
{
	wchar_t n;
	char	*str;
	char	*tmp;
	char	b;

	b = ' ';
	str = NULL;
	n = (wchar_t)arg->arg;
	(n <= 127) ? str = ft_mask1(n) : 0;
	(n > 127 && n <= 2047) ? str = ft_mask2(n) : 0;
	(n > 2047 && n <= 65535) ? str = ft_mask3(n) : 0;
	(n > 65535) ? str = ft_mask3(n) : 0;
	(arg->option[4] == 1) ? b = '0' : 0;
	(arg->width >= (int)ft_strlen(str)) ? tmp = ft_memset(ft_strnew(arg->width - ft_strlen(str)), b, arg->width - ft_strlen(str)) : 0;
	(arg->width < (int)ft_strlen(str)) ? tmp = "" : 0;
	(arg->option[0] == 1) ? str = ft_strjoin(str, tmp) : 0;
	(arg->option[0] == 0) ? str = ft_strjoin(tmp, str) : 0;
	arg->result = ft_strdup(str);
	free(str);
	return(0);
}

int		ft_wchar_string(t_arg *arg)
{
	wchar_t *wstr;
	char	*str;
	char	*tmp;
	int i;

	i = 0;
	wstr = (wchar_t*)arg->arg;
	str = "";
	tmp = "";
	while (wstr[i])
	{
		(wstr[i] <= 127) ? tmp = ft_mask1(wstr[i]) : 0;
		(wstr[i] > 127 && wstr[i] <= 2047) ? tmp = ft_mask2(wstr[i]) : 0;
		(wstr[i] > 2047 && wstr[i] <= 65535) ? tmp = ft_mask3(wstr[i]) : 0;
		(wstr[i] > 65535) ? tmp = ft_mask3(wstr[i]) : 0;
		str = ft_strjoin(str, tmp);
		i++;
	}
	free(tmp);
	(arg->width >= (int)ft_strlen(str)) ? tmp = ft_memset(ft_strnew(arg->width - ft_strlen(str)), ' ', arg->width - ft_strlen(str)) : 0;
	(arg->width < (int)ft_strlen(str)) ? tmp = "" : 0;
	(arg->option[0] == 1) ? arg->result = ft_strjoin(str, tmp) : 0;
	(arg->option[0] == 0) ? arg->result = ft_strjoin(tmp, str) : 0;
	free(str);
	return (0);
}
