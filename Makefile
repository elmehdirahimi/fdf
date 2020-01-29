# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erahimi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/28 18:32:09 by erahimi           #+#    #+#              #
#    Updated: 2019/10/22 19:23:14 by ibel-kha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS =  reader.c\
	   initializer.c\
	   views.c\
	   painter.c\
	   main.c\
	   controler.c\
	   color.c\
	   closer.c

OBJ = reader.o\
	  initializer.o\
	  views.o\
	   painter.o\
	   main.o\
	   controler.o\
	   color.o\
	   closer.o

LIBFT = -L libft -lft

CFLAGS = -Wall -Wextra -Werror

CC = gcc $(CFLAGS)

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft libft.a
	@$(CC) -o $@ $(OBJ) $(LIBFT) $(MLX)

%.o: %.c
	$(CC) -c $< -o $@ 

clean:
	@make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all
