/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:09:27 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/30 14:51:12 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_set_option(t_arg *arg)
{
	int	i;
	int	a;
	int h;
	int l;

	i = 0;
	l = 0;
	h = 0;
	arg->option = (char *)malloc(sizeof(char) * 11);
	arg->option = ft_memset(arg->option, 0, 11);
	while (arg->flags[i] || arg->lenght[i])
	{
		a = 0;
		(arg->flags[i] == '-') ?  arg->option[0] = 1 : a++;
		(arg->flags[i] == '+') ? arg->option[1] = 1 : a++;
		(arg->flags[i] == ' ') ? arg->option[2] = 1 : a++;
		(arg->flags[i] == '#') ? arg->option[3] = 1 : a++;
		(arg->flags[i] == '0') ? arg->option[4] = 1 : a++;
		(arg->lenght[i] == 'h') ? h++ : a++;
		(arg->lenght[i] == 'l') ? l++ : a++;
		(arg->lenght[i] == 'j') ? arg->option[9] = 1 : a++;
		(arg->lenght[i] == 'z') ? arg->option[10] = 1 : a++;
		if (a == 11)
		{
			ft_putstr("error");
			return (-1);
		}
		i++;
	}
	(h % 2 == 1 && h != 0) ? arg->option[6] = 1 : 0;
	(h % 2 == 0 && h != 0) ? arg->option[5] = 1 : 0;
	(l % 2 == 1 && l != 0) ? arg->option[8] = 1 : 0;
	(l % 2 == 0 && l != 0) ? arg->option[7] = 1 : 0;
	return(0);
}

int		ft_check_s_options(t_arg *arg)
{
	int i;

	i = 0;
	while (i < 11)
	{
		if (arg->option[i] == 1 && i != 0 && i != 8)
			return (-1);
		i++;
	}
	return (0);
}

void	ft_s_precision(t_arg *arg)
{
	int i;
	char *str;
	char *tmp;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen((char *)arg->arg));
	tmp = (char *)arg->arg;
	while (i < arg->precision)
	{
		str[i] = tmp[i];
		i++;
	}
	(arg->width == -1 || arg->width < arg->precision) ? arg->result = ft_strdup(str) : 0;
	if (arg->option[0] == 0 && arg->width != -1 && arg->width >= (int)ft_strlen(str))
		arg->result = ft_strjoin(ft_memset(ft_strnew(arg->width - ft_strlen(str)), ' ', arg->width - ft_strlen(str)), str);
	if (arg->option[0] == 1 && arg->width != -1)
		arg->result = ft_strjoin(str, ft_memset(ft_strnew(arg->width - ft_strlen(str)), ' ', arg->width - ft_strlen(str)));
}

int		ft_set_string(t_arg *arg)
{
	if (arg->arg == NULL)
	{
		arg->result = "(null)";
		return (0);
	}
	if (ft_check_s_options(arg) == -1)
		return(-1);
	if ((arg->option[0] == 1 || arg->option[0] == 0) && arg->precision == -1 && arg->width == -1)
		arg->result = (char *)arg->arg;
	if (arg->precision == -1 && arg->width != -1 && arg->option[0] == 0)
		arg->result = ft_strjoin(ft_memset(ft_strnew(arg->width - ft_strlen((char *)arg->arg)), ' ', arg->width - ft_strlen((char *)arg->arg)), (char *)arg->arg);
	if (arg->precision == -1 && arg->width != -1 && arg->option[0] == 1)
		arg->result = ft_strjoin((char *)arg->arg, ft_memset(ft_strnew(arg->width - ft_strlen((char *)arg->arg)), ' ', arg->width - ft_strlen((char *)arg->arg)));
	if (arg->precision != -1)
		ft_s_precision(arg);
	return(0);
}
