# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 11:53:55 by mlarra            #+#    #+#              #
#    Updated: 2023/02/27 15:40:07 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	check

SRC		=	main.cpp

HEADERS	=	vector/vector.hpp iterators/vector_iterator.hpp

OBJS	=	${SRC:%.cpp=%.o}

FLAGS	=	-g -Wall -Wextra -Werror -std=c++98

CC		=	c++

RM		=	rm -f

.PHONY	:	all clean fclean re

%.o		:	%.cpp ${HEADERS}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJS} ${HEADERS}
	${CC} ${FLAGS} ${SRC} -o $@

all		:	${NAME}

clean	:
	${RM} ${OBJS}

fclean	:	clean
	${RM} ${NAME}

re		:	fclean	all