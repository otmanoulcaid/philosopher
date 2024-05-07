# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 16:49:25 by ooulcaid          #+#    #+#              #
#    Updated: 2024/05/07 22:07:09 by ooulcaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
HEADER = philo_bonus.h
NAME = philo_bonus

SRCS = srcs/main.c\
		srcs/time.c\
		srcs/itoa.c \
		srcs/clean.c \
		srcs/parse.c  \
		srcs/routine.c \
		srcs/get_set.c  \
		srcs/supervisor.c\
		srcs/simulation.c \

OBJS = ${SRCS:.c=.o}

all : $(NAME)

%.o : %.c $(HEADER)
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(COMPILER) $(CFLAGS) -g $^ -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
