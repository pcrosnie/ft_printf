/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 14:18:44 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/04 13:01:33 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cast_d(t_arg *arg)
{
	char	*str;

	str = NULL;
	(ft_no_option(arg) == 1) ? str = ft_itoa_long((int)arg->arg) : 0;
	(arg->option[5] == 1) ? str = ft_itoa_long((signed char)arg->arg) : 0;
	(arg->option[6] == 1) ? str = ft_itoa_long((short int)arg->arg) : 0;
	(arg->option[7] == 1) ? str = ft_itoa_long((long long int)arg->arg) : 0;
	(arg->option[8] == 1) ? str = ft_itoa_long((long int)arg->arg) : 0;
	(arg->option[9] == 1) ? str = ft_itoa_long((intmax_t)arg->arg) : 0;
	(arg->option[10] == 1) ? str = ft_itoa_long((size_t)arg->arg) : 0;
	return (str);
}

void	ft_digit_options(t_arg *arg, char *tmp, char *tmp2, char b)
{
	(arg->width >= (int)ft_strlen(tmp)) ? tmp2 = ft_memset(ft_strnew(arg->width
				- ft_strlen(tmp)), b, arg->width - ft_strlen(tmp)) : 0;
	(arg->width < (int)ft_strlen(tmp)) ? tmp2 = "" : 0;
	(ft_no_option(arg) == 1 && arg->width > arg->precision &&
	arg->precision != -1 && arg->width != -1 &&
	arg->arg < 0) ? tmp[0] = '-' : 0;
	if (arg->option[0] == 1)
		arg->result = ft_strjoin(tmp, tmp2);
	else
		arg->result = ft_strjoin(tmp2, tmp);
	(arg->option[1] == 1 && (int)arg->arg > 0 && arg->option[4] == 1) ?
		arg->result[0] = '+' : 0;
	((int)arg->arg < 0 && arg->option[4] == 1) ? arg->result[0] = '-' : 0;
	((int)arg->arg < 0 && arg->option[4] == 1) ? arg->result[arg->width -
		ft_strlen(tmp)] = '0' : 0;
	(arg->width >= (int)ft_strlen(tmp)) ? free(tmp2) : 0;
}

void	ft_digit_s_char(t_arg *arg)
{
	char	*tmp;
	char	*tmp2;
	char	b;
	int		a;

	a = 0;
	tmp = ft_cast_d(arg);
	(tmp == NULL) ? tmp = "\0" : 0;
	(tmp[0] == '-') ? a = 1 : 0;
	tmp2 = (char *)malloc(sizeof(char) * (arg->width + ft_strlen(tmp) + 5));
	if (arg->precision != -1 && arg->precision > (int)ft_strlen(tmp))
		tmp = ft_set_d_s_char_prec(arg, &tmp, 0);
	(arg->option[1] == 1 && (int)arg->arg > 0 &&
	arg->option[4] == 0) ? tmp = ft_strjoin("+", tmp) : 0;
	if (arg->option[4] == 1 && arg->precision == -1)
		b = '0';
	else
		b = ' ';
	if (arg->option[2] == 1 && a == 0)
		tmp = ft_strjoin(" ", tmp);
	ft_digit_options(arg, tmp, tmp2, b);
}

char	*ft_scotch_d(t_arg *arg)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * arg->width);
	while (i < arg->width - arg->precision)
		str[i++] = ' ';
	while (i < arg->width)
		str[i++] = '0';
	str[i] = '\0';
	return (str);
}

int		ft_set_digit(t_arg *arg)
{
	if ((arg->precision == -2 || arg->precision == 0) && arg->arg == 0)
	{
		arg->result = "";
		return (0);
	}
	(arg->option[0] == 1) ? arg->option[4] = 0 : 0;
	(arg->option[1] == 1) ? arg->option[2] = 0 : 0;
	(arg->option[4] == 1 && arg->width != -1 && arg->precision != -1
	&& arg->width > arg->precision && arg->arg == 0) ? arg->result =
		ft_scotch_d(arg) : 0;
	if (arg->option[4] == 1 && arg->width != -1 &&
		arg->precision != -1 && arg->width > arg->precision && arg->arg == 0)
		return (0);
	if (arg->arg == '\0' && arg->precision == -1 && arg->width == -1)
	{
		arg->result = "0";
		(arg->option[1] == 1) ? arg->result = "+0" : 0;
		return (0);
	}
	ft_digit_s_char(arg);
	return (0);
}
