# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 17:04:36 by schoe             #+#    #+#              #
#    Updated: 2022/05/17 21:23:17 by schoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SRCS = ft_ultoa.c ft_u_convert_base.c ft_printf_utils.c ft_printf.c
OBJS = ${SRCS:.c=.o}
RM = rm -f
INCLUDE = -I./includes
NAME = libftprintf.a

all : $(NAME)

$(NAME) : ${OBJS}
		${MAKE} -C ./libft all
		ar -crs $(NAME) ${OBJS}

%.o : %.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INCLUDE}

clean :
		${MAKE} -C ./libft clean
		${RM} ${OBJS}

fclean : clean
		${MAKE} -C ./libft fclean
		${RM} $(NAME)

re : fclean all

.PHONY: all clean fclean re
