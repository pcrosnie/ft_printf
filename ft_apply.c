/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 14:27:38 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/03 15:09:32 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_false_specifier(int *safe)
{
	int i;

	i = 0;
	while (i < 13)
	{
		if (safe[i] == -1)
			return (-1);
		i++;
	}
	return (0);
}

void	ft_set_d_up_digit(t_arg *arg)
{
	arg->option[8] = 1;
	ft_set_digit(arg);
}

int		ft_set_other(t_arg *arg)
{
	char	*str;
	int		i;
	int		a;

	i = 0;
	a = 1;
	str = (char *)malloc(sizeof(char) * (10 + arg->width + arg->precision
				+ ft_strlen(arg->lenght)));
	if (arg->option[0] == 1)
	{
		str[i++] = arg->type;
		a = 0;
	}
	while (i < arg->width - a)
	{
		str[i++] = ' ';
	}
	if (arg->option[0] == 0)
		str[i++] = arg->type;
	str[i] = '\0';
	arg->result = ft_strdup(str);
	free(str);
	return (0);
}

int		ft_check_options(t_arg *arg)
{
	int a;

	a = 0;
	(arg->type == 's' && arg->option[8] == 0) ? ft_set_string(arg) : a++;
	(arg->type == 'S' || (arg->type == 's' &&
					arg->option[8] == 1)) ? ft_wchar_string(arg) : a++;
	(arg->type == 'd' || arg->type == 'i') ? ft_set_digit(arg) : a++;
	(arg->type == 'D') ? ft_set_d_up_digit(arg) : a++;
	(arg->type == 'p') ? ft_set_adress(arg) : a++;
	(arg->type == 'o') ? ft_set_octal(arg) : a++;
	(arg->type == 'O') ? ft_set_octal(arg) : a++;
	(arg->type == 'u') ? ft_set_u_digit(arg) : a++;
	(arg->type == 'U') ? ft_set_u_digit(arg) : a++;
	(arg->type == 'x') ? ft_set_hexa(arg) : a++;
	(arg->type == 'X') ? ft_set_hexa(arg) : a++;
	(arg->type == 'c' && arg->option[8] == 0) ? ft_set_char(arg) : a++;
	(arg->type == 'C' || (arg->type == 'c' &&
						arg->option[8] == 1)) ? ft_wchar(arg) : a++;
	(a == 13) ? ft_set_other(arg) : 0;
	if (a == 13)
		return (1);
	return (0);
}

int		ft_apply(t_arg *arg)
{
	while (arg->next != NULL)
	{
		if (ft_set_option(arg) == -1)
			return (-1);
		if (ft_check_options(arg) == -1)
			return (-1);
		arg = arg->next;
	}
	return (0);
}
