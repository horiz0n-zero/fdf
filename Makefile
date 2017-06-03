# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/30 11:56:24 by afeuerst          #+#    #+#              #
#    Updated: 2017/05/30 12:09:31 by afeuerst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

C_SRC = $(shell find . -type f | grep "\.c")

FLAGS = ./resource/libmlx.a -framework OpenGL -framework AppKit -O0 -fsanitize=address -g

INCLUDES = -I . -I ./resource/

all:
	make -j $(NAME)

$(NAME):
	clang $(FLAGS) $(C_SRC) $(INCLUDES) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all
