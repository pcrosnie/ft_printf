/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 13:00:51 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/04 13:05:00 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_d_option(t_arg *arg)
{
	int	i;
	int	a;

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

char	*ft_set_d_s_char_prec(t_arg *arg, char **tmp, int i)
{
	char	*str;
	char	*tmp2;
	int		j;

	j = 0;
	tmp2 = *tmp;
	str = (char *)malloc(sizeof(char) * (ft_strlen(tmp2) + arg->precision));
	(arg->precision != -1 && (arg->width > (int)ft_strlen(tmp2)
				|| arg->precision > (int)ft_strlen(tmp2)) &&
	ft_no_option(arg) == 1 && (int)arg->arg < 0) ? str[i++] = '-' : 0;
	((arg->type == 'o' || arg->type == 'O') && arg->width == -1
	&& arg->option[3] == 1) ? arg->precision-- : 0;
	while (i < arg->precision - (int)ft_strlen(tmp2) && arg->arg >= 0)
		str[i++] = '0';
	if (tmp2[j] == '-')
	{
		j++;
		str[i++] = '0';
		str[i++] = '0';
	}
	while (j < (int)ft_strlen(tmp2))
		str[i++] = tmp2[j++];
	str[i] = '\0';
	return (str);
}

int		ft_set_in_options(t_arg *arg, int i)
{
	int a;

	a = 0;
	(arg->flags[i] == '-') ? arg->option[0] = 1 : a++;
	(arg->flags[i] == '+') ? arg->option[1] = 1 : a++;
	(arg->flags[i] == ' ') ? arg->option[2] = 1 : a++;
	(arg->flags[i] == '#') ? arg->option[3] = 1 : a++;
	(arg->flags[i] == '0') ? arg->option[4] = 1 : a++;
	(arg->lenght[i] == 'j') ? arg->option[9] = 1 : a++;
	(arg->lenght[i] == 'z') ? arg->option[10] = 1 : a++;
	return (a);
}
