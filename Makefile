# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 21:05:38 by bel-bouz          #+#    #+#              #
#    Updated: 2018/11/10 16:26:18 by bel-bouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = srcs/ft_affich.c\
	  srcs/ft_cheking.c\
	  srcs/ft_fun.c\
	  srcs/ft_solve.c\
	  srcs/ft_strdup.c\
	  srcs/ft_strnew.c\
	  srcs/ft_tool.c\
	  srcs/get_next_line.c\

FLAGS = -Wall -Wextra -Werror
OBJ = $(notdir $(SRC:.c=.o))

all: $(NAME)

$(NAME) :
	@gcc $(FLAGS) -c $(SRC) -I srcs/includes/
	@gcc $(FLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
