/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:11:51 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/10 17:22:21 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

typedef struct	s_arg
{
	void	*arg;
	char	type;
	char	*precision;
	struct	s_arg *next;
}				t_arg;

int		ft_printf(const char *format, ...);

#endif
