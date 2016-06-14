/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 14:27:38 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/14 14:51:03 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_options(t_arg *arg)
{
	(arg->type == 's') ? ft_set_string(arg) : 0;
//	(arg->type == 'S') ? ft_set_wchar_string(arg) : 0;
//	(arg->type == 'd' || arg->type == 'i') ? ft_set_digit(arg) : 0;
//	(arg->type == 'D') ? ft_set_digit(arg) : 0;
//	(arg->type == 'p') ? ft_set_adrees(arg) : 0;
 //	(arg->type == 'o') ? 
 //	(arg->type == 'O') ?
 //	(arg->type == 'u') ? 
 //	(arg->type == 'U') ?
 //	(arg->type == 'x') ?
 //	(arg->type == 'X') ?
 //	(arg->type == 'c') ?
 //	(arg->type == 'C') ?

	return (0);
}

int		ft_apply(t_arg *arg)
{
	while (arg->next != NULL)
	{
		ft_set_option(arg);
		ft_check_options(arg);
		arg = arg->next;
	}
	return (0);
}
