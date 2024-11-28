# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariserr <mariserr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 07:49:28 by mariserr          #+#    #+#              #
#    Updated: 2024/11/24 18:30:37 by mariserr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES	=	main.c\
				events.c\
				init.c\
				render.c\
				utils_math.c\
				utils_string.c\
				burning_ship_bonus.c
				
SRCS_DIR	= src/

SRCS		= ${addprefix ${SRCS_DIR},${SRCS_FILES}}

OBJS_FILES	= ${SRCS_FILES:.c=.o}

OBJS_DIR	= bin/

OBJS		= ${addprefix ${OBJS_DIR},${OBJS_FILES}}

INCL_FILE	= fractol.h

INCL_DIR	= inc/

INCL		= ${addprefix ${INCL_DIR},${INCL_FILE}}

MLX_DIR		= mlx/

MLX			= -L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit

NAME		= fractol

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I${INCL_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${INCL}
	@mkdir -p ${OBJS_DIR}    #creer le dossier bin avec les .o
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${MAKE} -C ${MLX_DIR}       #compile mlx in the subfolder
			${CC} ${CFLAGS} ${OBJS} ${MLX} -o ${NAME}

all:	${NAME}

clean:
		${RM} -r ${OBJS_DIR} #-r pour enlever les repositories dans les reposit.(bin)
		${MAKE} -C ${MLX_DIR} clean

fclean:		clean
		${RM} ${NAME}
		${MAKE} -C ${MLX_DIR} fclean || echo "No 'fclean' target in ${MLX_DIR}, skipping..."

re:		fclean all


.PHONY: all clean fclean re
