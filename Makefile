# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 11:41:12 by lgirault          #+#    #+#              #
#    Updated: 2023/06/15 19:21:18 by lgirault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Werror -Wall -Wextra
RM = rm -rf

SRC = Pipex/pipex.c \
	Pipex/find_good_path.c \
	Pipex/make_tab_option.c \
	Pipex/make_tab_path.c \
	Pipex/free.c \
	Pipex/utils.c \
	Pipex/here_doc.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) Pipex/pipex.h
	make -C ./libft_tot/
	$(CC) $(CFLAGS) $(OBJ) libft_tot/libft.a -o $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C ./libft_tot/

fclean: clean
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re