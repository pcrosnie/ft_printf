/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:11:51 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/22 15:25:29 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

// options : 0 - 1 + 2 ' ' 3 # 4 0 5 hh 6 h 7 ll 8 l 9 j 10 z

typedef struct	s_arg
{
	void	*arg;
	char	type;
	char	*flags;
	char	*lenght;
	int		precision;
	int		width;
	char	*option;
	char	*result;
	struct	s_arg *next;
}				t_arg;

typedef struct	s_format
{
	char **format;
}				t_format;

int		ft_set_hexa(t_arg *arg);
char	*ft_set_maj(char *str);
char	*ft_set_d_s_char_prec(t_arg *arg, char **tmp);
int		ft_set_octal(t_arg *arg);
int		ft_no_option(t_arg *arg);
char	*ft_itoa_long(long long int c);
int		ft_set_digit(t_arg *arg);
int		ft_set_string(t_arg *arg);
int		ft_apply(t_arg *arg);
int		ft_check_options(t_arg *arg);
int		ft_set_option(t_arg *arg);
int		ft_retrieve_lenght(const char *format,t_arg *arg, int i);
int		ft_retrieve_width(const char *format,t_arg *arg, int i);
int		ft_retrieve_flags(const char *format, t_arg *arg, int i);
int		ft_printf(const char *format, ...);

#endif
