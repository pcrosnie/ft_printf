/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:00:48 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/14 14:43:28 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_retrieve_precision(const char *format, t_arg *arg, int i)
{
	int j;
	char *tmp;

	tmp = (char *)malloc(sizeof(char) * ft_strlen(format));
	j = 0;
	if (format[i] == '.')
	{
		i++;
		while (ft_isdigit(format[i]) == 1)
		{
			tmp[j] = format[i];
			i++;
			j++;
		}
		tmp[j] = '\0';
	arg->precision = ft_atoi(tmp);
	}
	else
		arg->precision = -1;
	free(tmp);
	return (i);
}

int		ft_check_format(const char *format, t_arg *arg, t_format *ptr)
{
	int	i;
	int	nb;
	int	j;
	int	k;

	i = 0;
	nb = 0;
	j = 0;
	k = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			i = ft_retrieve_flags(format, arg, i);
			i = ft_retrieve_width(format, arg, i);
			i = ft_retrieve_precision(format, arg, i);
			i = ft_retrieve_lenght(format, arg, i);
			arg->type = format[i++];
			arg->next = (t_arg *)malloc(sizeof(t_arg));
			arg->next->flags = (char *)malloc(sizeof(char) * 10);
			arg->next->lenght = (char *)malloc(sizeof(char) * 10);
			arg = arg->next;
			j++;
			if (format[i] != '\0')
			ptr->format[j] = (char *)malloc(sizeof(ft_strlen(format)));
			k = 0;
			nb++;
		}
		else
		{
			ptr->format[j][k] = format[i];
			k++;
			i++;
		}
	}
	ptr->format[j + 1] = NULL;
	return (nb);
}

t_arg	*ft_retrieves(const char *format, va_list ap, t_format *ptr)
{
	t_arg	*arg;
	t_arg	*tmp;
	int		i;

	arg = (t_arg *)malloc(sizeof(t_arg));
	arg->flags = (char *)malloc(sizeof(char) * 10);
	arg->lenght = (char *)malloc(sizeof(char) * 10);
	ptr->format = (char **)malloc(sizeof(char *) * ft_strlen(format));
	ptr->format[0] = (char *)malloc(sizeof(char) * ft_strlen(format));
	i = ft_check_format(format, arg, ptr);
	tmp = arg;
	while (i > 0)
	{
		arg->arg = va_arg(ap, void *);
		arg = arg->next;
		i--;
	}
	arg->next = NULL;
	arg = tmp;
/*	while (tmp->next != NULL)
	{
	ft_putstr(tmp->arg);
	ft_putstr(" : ");
	ft_putnbr(tmp->precision);
	ft_putstr(" : ");
	ft_putchar(tmp->type);
	ft_putstr(" : ");
	ft_putnbr(tmp->width);
	ft_putstr(" : ");
	ft_putstr(tmp->flags);
	ft_putstr(" : ");
	ft_putstr(tmp->lenght);
	ft_putstr(" : ");
	tmp = tmp->next;
	ft_putchar('\n');
	}
	i = 0;
	while (ptr->format[i])
	{
		ft_putstr(ptr->format[i++]);
		ft_putchar('\n');
	}*/
	return (arg);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_arg	*arg;
	t_format *ptr;

	ptr = (t_format *)malloc(sizeof(t_format));
	va_start(ap, format);
	arg = ft_retrieves(format, ap , ptr);
	ft_apply(arg);
	ft_putstr(arg->result);
	return (0);
}
