/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 14:18:44 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/21 16:22:30 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_d_option(t_arg *arg)
{
	int i;
	int a;

	i = 5;
	a = 0;
	if (arg->option[3] == 1)
		return (-1);
	if (arg->option[0] == 1 && arg->option[4] == 1)
		return (-1);
	if (arg->option[1] == 1 && arg->option[2] == 1)
		return (0);
	while (i < 11)
	{
		if (arg->option[i] == 1)
			a++;
		i++;
	}
	if (a > 1)
		return (-1);
	return (0);
}

char	*ft_set_sign(char *tmp, long long int c, int a)
{
	if (a == 1 && ft_strlen(tmp) > 0)
	{
		tmp[ft_strlen(tmp) - 1] = '\0';
	}
	if (c >= 0)
		return (ft_strjoin("+", tmp));
	else
		return (ft_strjoin("-", tmp));
}

char	*ft_set_d_s_char_prec(t_arg *arg, char **tmp)
{
	char	*str;
	char	*tmp2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp2 = *tmp;
	str = (char *)malloc(sizeof(char) * (ft_strlen(tmp2) + arg->precision));
	(arg->option[1] == 1 && arg->option[4] == 0 && ft_isdigit(tmp2[0]) == 1) ? str[i++] = '+' : 0;
	((arg->option[1] == 1 && arg->option[4] == 0 && ft_isdigit(tmp2[0]) != 1) || tmp2[0] == '-') ? str[i++] = '-' : 0;
	while (i < arg->precision - (int)ft_strlen(tmp2))
	{
		str[i] = '0';
		i++;
	}
	if (tmp2[j] == '-')
	{
		j++;
		str[i++] = '0';
		str[i++] = '0';
	}
	while (j < (int)ft_strlen(tmp2))
	{
		str[i] = tmp2[j];
		i++;
		j++;
	}
	str[i] = '\0';
//	free(&*tmp);
	return (str);
}

char	*ft_cast_d(t_arg *arg)
{
	char	*str;

	str = NULL;
	(arg->option[5] == 1) ? str = ft_itoa_long((signed char)arg->arg) : 0;
	(arg->option[6] == 1) ? str = ft_itoa_long((short int)arg->arg) : 0;
	(arg->option[7] == 1) ? str = ft_itoa_long((long long int)arg->arg) : 0;
	(arg->option[8] == 1) ? str = ft_itoa_long((long int)arg->arg) : 0;
	(arg->option[9] == 1) ? str = ft_itoa_long((intmax_t)arg->arg) : 0;
	(arg->option[10] == 1) ? str = ft_itoa_long((size_t)arg->arg) : 0;
	return (str);
}

void	ft_digit_s_char(t_arg *arg)
{
	char *tmp;
	char *tmp2;
	char b;
	int	a;

	a = 0;
	tmp = ft_cast_d(arg);
	(tmp[0] == '-') ? a = 1 : 0;
	tmp2 = (char *)malloc(sizeof(char) * (arg->width + ft_strlen(tmp) + 5));
	if (arg->precision != -1 && arg->precision > (int)ft_strlen(tmp))
	tmp = ft_set_d_s_char_prec(arg, &tmp);
	if (arg->option[4] == 1)
	   	b = '0';
	else
		b = ' ';
//	if (arg->option[1] == 1 && arg->option[4] == 0)
//		tmp = ft_set_sign(tmp, c, 0);
	if (arg->option[2] == 1 && a == 0)
	{
		ft_putchar('Z');
		tmp = ft_strjoin(" ", tmp);
	}
	(arg->width > (int)ft_strlen(tmp)) ? tmp2 = ft_memset(ft_strnew(arg->width - ft_strlen(tmp)), b, arg->width - ft_strlen(tmp)) : 0;
	(arg->width < (int)ft_strlen(tmp)) ? tmp2 = "" : 0;
//	(arg->option[1] == 1 && arg->option[4] == 1) ? tmp2 = ft_set_sign(tmp2, c, 1) : 0;
	if (arg->option[0] == 1)
		arg->result = ft_strjoin(tmp, tmp2);
	else 
		arg->result = ft_strjoin(tmp2, tmp);
	free(tmp);
	(arg->width >= (int)ft_strlen(tmp))? free(tmp2) : 0;
}

int		ft_set_digit(t_arg *arg)
{
	if (ft_check_d_option(arg) == -1)
		return (-1);
	ft_digit_s_char(arg);
	return (0);
}
