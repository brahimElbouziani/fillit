# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 21:05:38 by bel-bouz          #+#    #+#              #
#    Updated: 2018/11/07 23:23:22 by bel-bouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = *.c
OBJ = *.o
LIB = libft/libft.a
FLAGS = gcc -Wall -Wextra -Werror

all: $(NAME)
$(NAME) :
	@make -C libft/ re
	@$(FLAGS)  $(SRC)  $(LIB) -o  $(NAME)
clean:
	@rm -f $(OBJ)
	@make  -C libft/ clean
fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
re: fclean all
