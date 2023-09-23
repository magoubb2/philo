# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 15:26:01 by mabaron-          #+#    #+#              #
#    Updated: 2023/09/23 13:42:09 by mabaron-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c parsing.c parsing_utils.c routine.c utils.c

OBJS =	${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

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