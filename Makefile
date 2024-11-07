# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 09:49:36 by barbizu-          #+#    #+#              #
#    Updated: 2022/10/03 11:55:28 by barbizu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = so_long

SRCS = main.c error_utils.c moves.c utils.c moves_utils.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

${NAME}: libft
		${CC} ${CFLAGS} ${SRCS} MLX42/libmlx42.a libft/libft.a -lglfw -L /sgoinfre/goinfre/Perso/barbizu-/homebrew/opt/glfw/lib -o ${NAME}

all:	${NAME}

libft:
	make -C ./libft

clean:
		${RM} -f ${OBJS}
		make clean -C ./libft

fclean:	clean
		make fclean -C ./libft
		${RM} -f ${NAME}

re:		fclean ${MAKE} ${NAME}

.PHONY: all clean fclean re libft
