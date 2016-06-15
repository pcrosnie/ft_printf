# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/20 12:13:09 by pcrosnie          #+#    #+#              #
#    Updated: 2016/06/15 16:04:34 by pcrosnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

FLAGS = -Wall -Werror -Wextra

SRC = libft/libft.a main.c ft_printf.c ft_retrieves_flags_n_width.c ft_set_string.c ft_apply.c ft_set_digit.c

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -o $(NAME) $(FLAGS) $(SRC)

clean:
	make -C libft/ fclean
		
fclean: clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
