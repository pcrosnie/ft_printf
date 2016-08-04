/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 13:18:24 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/04 12:49:37 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_o_options(t_arg *arg)
{
	if (arg->option[1] == 1 || arg->option[2] == 1)
		return (-1);
	if (arg->option[0] == 1 && arg->option[4] == 1)
		return (-1);
	return (0);
}

char	*ft_cast_o_option(t_arg *arg)
{
	char	*str;

	str = NULL;
	(ft_no_option(arg)) ? str = ft_ull_base((unsigned int)arg->arg, 8) : 0;
	(arg->option[5] == 1) ? str = ft_ull_base((unsigned char)arg->arg, 8) : 0;
	(arg->option[6] == 1) ? str =
	ft_ull_base((unsigned short int)arg->arg, 8) : 0;
	(arg->option[7] == 1) ? str =
	ft_ull_base((unsigned long long int)arg->arg, 8) : 0;
	(arg->option[8] == 1) ? str =
	ft_ull_base((unsigned long int)arg->arg, 8) : 0;
	(arg->option[9] == 1) ? str = ft_ull_base((uintmax_t)arg->arg, 8) : 0;
	(arg->option[10] == 1) ? str = ft_ull_base((size_t)arg->arg, 8) : 0;
	return (str);
}

char	*ft_set_maj(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_islower(str[i]) == 1)
			str[i] -= 32;
		i++;
	}
	return (str);
}

void	ft_set_octal_options(t_arg *arg, char *tmp, char *tmp2, char b)
{
	if (arg->precision != -1 && arg->precision > (int)ft_strlen(tmp))
		tmp = ft_set_d_s_char_prec(arg, &tmp, 0);
	(arg->width > (int)ft_strlen(tmp)) ? tmp2 = ft_memset(ft_strnew(arg->width
	- ft_strlen(tmp)), b, arg->width - ft_strlen(tmp)) : 0;
	(arg->width <= (int)ft_strlen(tmp)) ? tmp2 = "" : 0;
	if (arg->option[0] == 1 && (int)arg->arg != 0)
	{
		(arg->option[3] == 1 && arg->precision < (int)ft_strlen(tmp)) ? tmp =
	ft_strjoin("0", tmp) : 0;
		arg->result = ft_strjoin(tmp, tmp2);
	}
	else if (arg->arg != 0)
	{
		(arg->option[3] == 1 && arg->width >= (int)ft_strlen(tmp)) ?
		tmp2[ft_strlen(tmp2) - 1] = '0' : 0;
		(arg->option[3] == 1 && arg->width < (int)ft_strlen(tmp)) ?
		tmp2 = "0" : 0;
		arg->result = ft_strjoin(tmp2, tmp);
	}
	else
		arg->result = "0";
}

int		ft_set_octal(t_arg *arg)
{
	char	*tmp;
	char	*tmp2;
	char	b;

	b = ' ';
	tmp2 = NULL;
	(arg->option[0] == 1) ? arg->option[4] = 0 : 0;
	if ((long long)arg->arg == 0 && arg->option[3] == 0 &&
	arg->width == -1 && (arg->precision == 0 || arg->precision == -2))
	{
		arg->result = "";
		return (0);
	}
	if (ft_check_o_options(arg) == -1)
		return (-1);
	(arg->option[4] == 1 && arg->precision == -1) ? b = '0' : 0;
	(arg->type == 'O') ? arg->option[8] = 1 : 0;
	(arg->option[0] == 1 && arg->option[3] == 1) ? arg->width-- : 0;
	tmp = ft_cast_o_option(arg);
	ft_set_octal_options(arg, tmp, tmp2, b);
	free(tmp);
	(arg->width >= (int)ft_strlen(tmp)) ? free(tmp2) : 0;
	return (0);
}
