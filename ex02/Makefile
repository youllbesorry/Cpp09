# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 13:09:56 by bfaure            #+#    #+#              #
#    Updated: 2024/05/01 13:09:56 by bfaure           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

############## VARIABLES ##############

NAME = PmergeMe

CC = c++ -std=c++98

############## FLAGS ##############

DEPS_FLAGS = -MMD -MP

CFLAGS = ${DEPS_FLAGS} -Wall -Wextra -Werror -g3

############## SOURCES ##############

SRC 	=	srcs/main.cpp \
			srcs/PmergeMe.cpp \

############## DIRECTORIES ##############

DIR_OBJS = .objs

############## OBJECTS ##############

OBJS = $(addprefix $(DIR_OBJS)/, $(SRC:.cpp=.o))

DEPS = ${SRC:%.cpp=${DIR_OBJS}/%.d}

############## RULES ##############

${NAME}	: ${OBJS}
			${CC} ${CFLAGS} -I ./Includes -o $@ $^

-include ${DEPS}

${DIR_OBJS}/%.o: %.cpp
	@mkdir -p $(shell dirname $@)
	${CC} ${CFLAGS} -I ./Includes -o $@ -c $<

all 	: ${NAME}

clean	:
			rm -rf ${DIR_OBJS}

fclean	: clean
			rm -f ${NAME}

re		: fclean
			$(MAKE)

############## PHONY ##############

.PHONY: all clean fclean re