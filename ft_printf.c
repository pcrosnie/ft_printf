/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:00:48 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/04 10:04:44 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_retrieve_precision(const char *format, t_arg *arg, int i)
{
	int		j;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * ft_strlen(format));
	j = 0;
	if (format[i] == '.' && ft_isdigit(format[i + 1]) == 0)
	{
		arg->precision = -2;
		return (i + 1);
	}
	if (format[i] == '.')
	{
		i++;
		while (ft_isdigit(format[i]) == 1)
		{
			tmp[j] = format[i++];
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

int		ft_fill_format(t_arg *arg, const char *format, int i)
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
	return (i);
}

void	ft_secure_format(int k, int j, t_format *ptr)
{
	(k != 0) ? ptr->format[j][k] = '\0' : 0;
	(k == 0) ? ptr->format[j] = NULL : 0;
	ptr->format[j + 1] = NULL;
}

int		ft_check_format(const char *format, t_arg *arg, t_format *ptr, int nb)
{
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (format && format[i[0]])
	{
		if (format[i[0]] == '%' && format[i[0] + 1] != '%')
		{
			i[0] = ft_fill_format(arg, format, i[0]);
			arg = arg->next;
			ptr->format[i[1]++][i[2]] = '\0';
			if (format[i[0]] != '\0')
				ptr->format[i[1]] = (char *)malloc(sizeof(ft_strlen(format)));
			i[2] = 0;
			nb++;
		}
		else
		{
			(format[i[0]] == '%' && format[i[0] + 1] == '%') ? i[0]++ : 0;
			ptr->format[i[1]][i[2]++] = format[i[0]++];
		}
	}
	ft_secure_format(i[2], i[1], ptr);
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
	i = ft_check_format(format, arg, ptr, 0);
	tmp = arg;
	while (i > 0)
	{
		arg->arg = va_arg(ap, void *);
		arg = arg->next;
		i--;
	}
	arg->next = NULL;
	arg = tmp;
	return (arg);
}

int		ft_output(const char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int		ft_c_display(t_arg *arg)
{
	int		i;
	int		n;
	char	c;

	i = 0;
	n = 0;
	c = '\0';
	if (arg->option[0] == 1)
		n += write(1, &c, 1);
	c = ' ';
	while (i < arg->width - 1)
	{
		n += write(1, &c, 1);
		i++;
	}
	c = '\0';
	if (arg->option[0] == 0)
		n += write(1, &c, 1);
	return (n);
}

int		ft_display(t_arg *arg, t_format *ptr)
{
	t_arg	*tmp;
	int		i;
	int		n;

	tmp = arg;
	i = 0;
	n = 0;
	while (ptr->format[i] != NULL)
	{
		n += ft_output(ptr->format[i]);
		if (arg->result)
		{
			if ((char)arg->arg == '\0' &&
					(arg->type == 'c' || arg->type == 'C'))
				n += ft_c_display(arg);
			else
				n += ft_output(arg->result);
			arg = arg->next;
		}
		i++;
	}
	return (n);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_arg		*arg;
	t_format	*ptr;

	arg = NULL;
	if (format)
	{
		ptr = (t_format *)malloc(sizeof(t_format) * 10);
		va_start(ap, format);
		arg = ft_retrieves(format, ap, ptr);
		arg->n = 0;
		if (ft_apply(arg) == -1)
			return (-1);
		return (ft_display(arg, ptr));
	}
	return (0);
}
