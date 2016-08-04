/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 12:48:14 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/04 12:57:41 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_no_option(t_arg *arg)
{
	int i;
	int a;

	i = 5;
	a = 0;
	while (i < 11)
	{
		(arg->option[i] == 1) ? a++ : 0;
		i++;
	}
	if (a == 0)
		return (1);
	return (0);
}

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
