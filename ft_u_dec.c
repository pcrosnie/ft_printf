/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_dec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 09:48:40 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/04 11:29:56 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cast_u(t_arg *arg)
{
	char	*str;

	str = NULL;
	(ft_no_option(arg) == 1) ? str =
	ft_ull_base((unsigned int)arg->arg, 10) : 0;
	(arg->option[5] == 1) ? str =
	ft_ull_base((unsigned char)arg->arg, 10) : 0;
	(arg->option[6] == 1) ? str =
	ft_ull_base((unsigned short int)arg->arg, 10) : 0;
	(arg->option[7] == 1) ? str =
	ft_ull_base((unsigned long long int)arg->arg, 10) : 0;
	(arg->option[8] == 1) ? str =
	ft_ull_base((unsigned long int)arg->arg, 10) : 0;
	(arg->option[9] == 1) ? str = ft_ull_base((uintmax_t)arg->arg, 10) : 0;
	(arg->option[10] == 1) ? str = ft_ull_base((size_t)arg->arg, 10) : 0;
	return (str);
}

void	ft_digit(t_arg *arg)
{
	char	*tmp;
	char	*tmp2;
	char	b;
	int		a;

	a = 0;
	tmp = ft_cast_u(arg);
	(tmp[0] == '-') ? a = 1 : 0;
	tmp2 = (char *)malloc(sizeof(char) * (arg->width + ft_strlen(tmp) + 5));
	if (arg->precision != -1 && arg->precision > (int)ft_strlen(tmp))
		tmp = ft_set_d_s_char_prec(arg, &tmp, 0);
	if (arg->option[4] == 1)
		b = '0';
	else
		b = ' ';
	if (arg->option[2] == 1 && a == 0)
		tmp = ft_strjoin(" ", tmp);
	(arg->width > (int)ft_strlen(tmp)) ? tmp2 = ft_memset(ft_strnew(arg->width
			- ft_strlen(tmp)), b, arg->width - ft_strlen(tmp)) : 0;
	(arg->width < (int)ft_strlen(tmp)) ? tmp2 = "" : 0;
	if (arg->option[0] == 1)
		arg->result = ft_strjoin(tmp, tmp2);
	else
		arg->result = ft_strjoin(tmp2, tmp);
	(arg->width >= (int)ft_strlen(tmp)) ? free(tmp2) : 0;
}

int		ft_set_u_digit(t_arg *arg)
{
	if ((arg->precision == -2 || arg->precision == 0) && arg->arg == 0)
	{
		arg->result = "";
		return (0);
	}
	if (ft_check_d_option(arg) == -1)
		return (-1);
	(arg->type == 'U') ? arg->option[8] = 1 : 0;
	ft_digit(arg);
	return (0);
}
