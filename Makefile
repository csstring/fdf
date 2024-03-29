# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 17:04:36 by schoe             #+#    #+#              #
#    Updated: 2022/05/20 17:21:53 by schoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
SRCS = main.c color.c draw_line.c error.c free.c get_distance.c iso.c \
	   key.c map.c map_utils.c
OBJS = ${SRCS:.c=.o}
RM = rm -f
INCLUDE = -I./includes
NAME = fdf

all : $(NAME)

$(NAME) : ${OBJS}
		${MAKE} -C ./libft all
		${MAKE} -C ./minilibx
		mv ./minilibx/libmlx.dylib .
		${CC} ${CFLAGS} -framework Metal -framework MetalKit libmlx.dylib \
		${OBJS} libft.a -o fdf

%.o : %.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INCLUDE}

clean :
		${MAKE} -C ./libft clean
		${MAKE} -C ./minilibx clean
		${RM} ${OBJS}

fclean : clean
		${MAKE} -C ./libft fclean
		${RM} $(NAME) libmlx.dylib

re : 
	${MAKE} fclean 
	${MAKE} all

.PHONY: all clean fclean re
