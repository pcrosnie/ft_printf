# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/24 13:16:13 by pcrosnie          #+#    #+#              #
#    Updated: 2016/06/24 13:17:17 by pcrosnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ME = libftprintf.a
LIB = libft/libft.a
SRC = ft_apply.c ft_ull_base.c ft_mask.c ft_wchar.c ft_itoa_long.c ft_printf.c ft_retrieves_flags_n_width.c ft_set_digit.c ft_set_string.c ft_set_octal.c ft_set_hexa.c ft_set_char.c ft_u_dec.c ft_set_adress.c

SRCO = $(SRC:.c=.o)
	FLAG = -Wall -Werror -Wextra

all: $(NAME)


$(NAME): $(SRCO)
	make -C libft
	gcc $(FLAG) -c $(SRC)
	cp $(LIB) $(NAME)
	ar r $(NAME) $(SRCO)
	ranlib $(NAME)

clean:
	make -C libft clean
	rm -f $(SRCO)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
