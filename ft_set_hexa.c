/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:16:09 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/03 17:12:18 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_x_options(t_arg *arg)
{
	if (arg->option[1] == 1 || arg->option[2] == 1)
		return (-1);
	if (arg->option[0] == 1 && arg->option[4] == 1)
		return (-1);
	return (0);
}

char	*ft_cast_x_option(t_arg *arg)
{
	char	*str;

	str = NULL;
	(ft_no_option(arg)) ? str = ft_ull_base((unsigned int)arg->arg, 16) : 0;
	(arg->option[5] == 1) ? str = ft_ull_base((unsigned char)arg->arg, 16) : 0;
	(arg->option[6] == 1) ? str =
	ft_ull_base((unsigned short int)arg->arg, 16) : 0;
	(arg->option[7] == 1) ? str =
	ft_ull_base((unsigned long long int)arg->arg, 16) : 0;
	(arg->option[8] == 1) ? str =
	ft_ull_base((unsigned long int)arg->arg, 16) : 0;
	(arg->option[9] == 1) ? str = ft_ull_base((uintmax_t)arg->arg, 16) : 0;
	(arg->option[10] == 1) ? str = ft_ull_base((size_t)arg->arg, 16) : 0;
	return (str);
}

void	ft_set_hexa_no_flag(t_arg *arg, char *tmp, char *tmp2)
{
	if (arg->option[0] == 1)
	{
		arg->result = ft_strjoin(tmp, tmp2);
		(arg->option[3] == 1) ? arg->result = ft_strjoin("0x", arg->result) : 0;
	}
	else
	{
		(arg->option[3] == 1 && arg->width >= (int)ft_strlen(tmp) &&
		arg->option[4] == 0) ? tmp2[ft_strlen(tmp2) - 2] = '0' : 0;
		(arg->option[3] == 1 && arg->width >= (int)ft_strlen(tmp) &&
		arg->option[4] == 0) ? tmp2[ft_strlen(tmp2) - 1] = 'x' : 0;
		(arg->option[3] == 1 && arg->width < (int)ft_strlen(tmp)) ?
		tmp2 = "0x" : 0;
		(arg->option[3] == 1 && arg->width >= (int)ft_strlen(tmp) &&
		arg->option[4] == 1) ? tmp2[0] = '0' : 0;
		(arg->option[3] == 1 && arg->width >= (int)ft_strlen(tmp) &&
		arg->option[4] == 1) ? tmp2[1] = 'x' : 0;
		arg->result = ft_strjoin(tmp2, tmp);
	}
}

int		ft_set_hexa(t_arg *arg)
{
	char	*tmp;
	char	*tmp2;
	char	b;

	b = ' ';
	if ((long long int)arg->arg == 0 && arg->width == -1)
	{
		(arg->precision <= 0 && arg->option[3] == 1) ? arg->result = "" : 0;
		(arg->precision == -1) ? arg->result = "0" : 0;
		return (0);
	}
	(arg->option[0] == 1) ? arg->option[4] = 0 : 0;
	(arg->option[0] == 1 && arg->option[3] == 1) ? arg->width -= 2 : 0;
	(arg->option[4] == 1 && arg->precision == -1) ? b = '0' : 0;
	tmp = ft_cast_x_option(arg);
	if (arg->precision != -1 && arg->precision > (int)ft_strlen(tmp))
		tmp = ft_set_d_s_char_prec(arg, &tmp);
	(arg->width >= (int)ft_strlen(tmp)) ? tmp2 = ft_memset(ft_strnew(arg->width
		- ft_strlen(tmp)), b, arg->width - ft_strlen(tmp)) : 0;
	(arg->width < (int)ft_strlen(tmp)) ? tmp2 = "" : 0;
	ft_set_hexa_no_flag(arg, tmp, tmp2);
	(arg->type == 'X') ? arg->result = ft_set_maj(arg->result) : 0;
	free(tmp);
	(arg->width >= (int)ft_strlen(tmp)) ? free(tmp2) : 0;
	return (0);
}
