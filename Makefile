# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 16:55:24 by mle-duc           #+#    #+#              #
#    Updated: 2024/03/06 12:01:28 by mle-duc          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			cub3D

CC =			cc

RM =			rm -f

INC_DIR =		./inc

LIBFT_DIR =		./libft

SRCS =			$(addprefix src/, \
				$(addprefix graphics/, \
				render.c \
				event.c \
				img_pix_put.c \
				init_data.c \
				init_data2.c \
				raycast.c \
				raycast2.c \
				textures.c \
				load_textures.c \
				calculations.c \
				cub3d.c) \
				$(addprefix parsing/, \
				check_path.c \
				convert_map.c \
				free.c \
				initialisartion.c \
				map_checker.c \
				parsing_map.c \
				parsing.c \
				position.c \
				utils_line.c \
				utils_list.c \
				utils_print.c \
				utils.c \
				utils2.c \
				utils3.c \
				wall_checker.c) \
				main.c)

OBJS =			${SRCS:.c=.o}

CFLAGS =		-g3 -Wall -Werror -Wextra

LIBFT_PATH =	libft/libft.a

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -I $(INC_DIR) -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C libft
	make -C mlx_linux
	$(CC) $(OBJS) ${CFLAGS} -L${LIBFT_DIR} -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	${RM} ${OBJS}
	make clean -C libft
	make clean -C mlx_linux

fclean: clean
	${RM} ${NAME}
	make fclean -C libft
	make clean -C mlx_linux

re: fclean all

.PHONY: all clean fclean re
