/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 14:27:38 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/23 11:48:02 by pcrosnie         ###   ########.fr       */
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

int		ft_check_options(t_arg *arg)
{
	int a;
	int	*safe;

	a = 0;
	safe = (int *)malloc(sizeof(int) * 13);
	safe = ft_memset(safe, 0, 13);
	(arg->type == 's') ? safe[0] = ft_set_string(arg) : a++;
//	(arg->type == 'S') ? ft_set_wchar_string(arg) : 0;
	(arg->type == 'd' || arg->type == 'i') ? ft_set_digit(arg) : a++;
	(arg->type == 'D') ? ft_set_d_up_digit(arg) : a++;
//	(arg->type == 'p') ? ft_set_adress(arg) : 0;
	(arg->type == 'o') ? ft_set_octal(arg) : a++;
 	(arg->type == 'O') ? ft_set_octal(arg) : a++;
 //	(arg->type == 'u') ? 
 //	(arg->type == 'U') ?
 	(arg->type == 'x') ? ft_set_hexa(arg) : a++;
 	(arg->type == 'X') ? ft_set_hexa(arg) : a++;
 //	(arg->type == 'c') ?
 	(arg->type == 'C') ? ft_wchar(arg) : a++;

	if (a == 8 || ft_check_false_specifier(safe) == -1)
		return(-1);
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
