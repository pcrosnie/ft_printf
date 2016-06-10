/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:00:48 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/10 17:40:08 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_retrieve_precision(const char *format, t_arg *arg, int i)
{
	int j;

	j = 0;
	while (format[i] == '.' || ft_isdigit(format[i]) == 1)
	{
		arg->precision[j] = format[i];
		i++;
		j++;
	}
	return (i);
}

int		ft_check_format(const char *format, t_arg *arg)
{
	int	i;
	int	nb;
	int	j;

	i = 0;
	nb = 0;
	while (format[i])
	{
		j = 0;
		if (format[i] == '%')
		{
			i++;
			i = ft_retrieve_precision(format, arg, i);
			arg->type = format[i];
			arg->next = (t_arg *)malloc(sizeof(t_arg));
			arg->next->precision = (char *)malloc(sizeof(char) * 10);
			arg = arg->next;
			nb++;
		}
		i++;
	}
	return (nb);
}

int		ft_retrieves(const char *format, va_list ap)
{
	t_arg	*arg;
	t_arg	*tmp;
	int		i;

	arg = (t_arg *)malloc(sizeof(t_arg));
	i = ft_check_format(format, arg);
	tmp = arg;
	while (i > 0)
	{
		arg->arg = va_arg(ap, void *);
		arg = arg->next;
		i--;
	}
	arg->next = NULL;
	while (tmp->next != NULL)
	{
	ft_putstr(tmp->arg);
	ft_putstr(" : ");
	ft_putstr(tmp->precision);
	ft_putstr(" : ");
	ft_putchar(tmp->type);
	ft_putchar('\n');
	tmp = tmp->next;
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	ft_retrieves(format, ap);
	return (0);
}
