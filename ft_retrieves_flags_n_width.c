/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retrieves_flags_n_width.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 10:30:03 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/07/27 13:20:44 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_retrieve_flags(const char *format, t_arg *arg, int i)
{
	int	j;

	j = 0;
	while (format[i] == '+' || format[i] == '-' ||
			format[i] == ' ' || format[i] == '0' || format[i] == '#')
	{
		arg->flags[j] = format[i];
		j++;
		i++;
	}
	arg->flags[j] = '\0';
	return (i);
}

int		ft_retrieve_width(const char *format, t_arg *arg, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(format));
	if (ft_isdigit(format[i]) == 1)
	{
		while (ft_isdigit(format[i]) == 1)
		{
			tmp[j] = format[i];
			j++;
			i++;
		}
		tmp[j] = '\0';
		arg->width = ft_atoi(tmp);
	}
	else
		arg->width = -1;
	free(tmp);
	return (i);
}

int		ft_retrieve_lenght(const char *format, t_arg *arg, int i)
{
	int	j;

	j = 0;
	while (format[i] == 'h' || format[i] == 'l'
			|| format[i] == 'z' || format[i] == 'j')
	{
		arg->lenght[j] = format[i];
		i++;
		j++;
	}
	arg->lenght[j] = '\0';
	return (i);
}
