/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:09:27 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/13 16:19:44 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_set_option(t_arg *arg)
{
	int	i;
	int	a;

	i = 0;
	arg->option = (char *)malloc(sizeof(char) * 11);
	arg->option = ft_memset(arg->option, 0, 11);
	while (arg->flags[i] || arg->lenght[i])
	{
		a = 0;
		(arg->flags[i] == '-') ?  arg->option[0] = 1 : a++;;
		(arg->flags[i] == '+') ? arg->option[1] = 1 : a++;
		(arg->flags[i] == ' ') ? arg->option[2] = 1 : a++;
		(arg->flags[i] == '#') ? arg->option[3] = 1 : a++;
		(arg->flags[i] == '0') ? arg->option[4] = 1 : a++;
		(arg->lenght[i] == 'h' && (arg->lenght[i + 1] == 'h' || arg->lenght[i - 1] == 'h')) ? arg->option[5] = 1 : a++;
		(arg->lenght[i] == 'h' && arg->lenght[i + 1] != 'h' && arg->lenght[i - 1] != 'h') ? arg->option[6] = 1 : a++;
		(arg->lenght[i] == 'l' && (arg->lenght[i + 1] == 'l' || arg->lenght[i - 1] == 'l')) ? arg->option[7] = 1 : a++;
		(arg->lenght[i] == 'l' && arg->lenght[i + 1] != 'l' && arg->lenght[i - 1] != 'l') ? arg->option[8] = 1 : a++;
		(arg->lenght[i] == 'j') ? arg->option[9] = 1 : a++;
		(arg->lenght[i] == 'z') ? arg->option[10] = 1 : a++;
		if (a == 11)
		{
			ft_putstr("error");
			return (-1);
		}
		i++;
	}
	return(0);
}

int		ft_set_string(t_arg *arg)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (arg->witdh + arg->precision + ft_strlen((char *)arg->arg)));
	while (i < 	
	return(0);
}
