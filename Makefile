# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/20 12:13:09 by pcrosnie          #+#    #+#              #
#    Updated: 2016/06/22 10:51:29 by pcrosnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

FLAGS = -Wall -Wextra -Werror

SRC = ft_apply.c ft_itoa_long.c ft_printf.c ft_retrieves_flags_n_width.c ft_set_digit.c ft_set_string.c main.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/ all
	gcc $(FLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
