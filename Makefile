# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 16:55:24 by mle-duc           #+#    #+#              #
#    Updated: 2024/02/17 00:26:38 by mle-duc          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			cub3d

CC =			cc

RM =			rm -f

INC_DIR =		./inc

LIBFT_DIR =		./libft

SRCS =			$(addprefix src/, \
				main.c)

OBJS =			${SRCS:.c=.o}

CFLAGS =		-g3 -Wall -Werror -Wextra

LIBFT_PATH =	libft/libft.a

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -I $(INC_DIR) -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C libft
	$(CC) $(OBJS) ${CFLAGS} -L${LIBFT_DIR} -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	${RM} ${OBJS}
	make clean -C libft

fclean: clean
	${RM} ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
