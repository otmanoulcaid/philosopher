# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 11:03:34 by ooulcaid          #+#    #+#              #
#    Updated: 2024/05/06 21:15:23 by ooulcaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
HEADER = philo.h
NAME = philo

SRCS = srcs/main.c    \
		srcs/time.c    \
		srcs/parse.c    \
		srcs/routine.c   \
		srcs/cleaning.c   \
		srcs/supervising.c \
		srcs/setter_getter.c\

OBJS = ${SRCS:.c=.o}

all : $(NAME)

%.o : %.c $(HEADER)
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(COMPILER) -g $(CFLAGS) $^ -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
