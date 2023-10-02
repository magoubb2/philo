# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 15:26:01 by mabaron-          #+#    #+#              #
#    Updated: 2023/10/02 15:23:02 by mabaron-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c parsing.c parsing_utils.c routine.c routine_utils.c monitor.c

OBJS =	${SRCS:.c=.o}

CC = gcc
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread
CFLAGS = -Wall -Wextra -Werror -g -O3

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean: 
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re