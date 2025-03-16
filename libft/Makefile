# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 20:35:06 by lenygarcia        #+#    #+#              #
#    Updated: 2025/03/10 21:31:22 by lenygarcia       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc -g
CFLAGS	= -Wall -Wextra -Werror
SRCS	= $(filter-out %_bonus.c, $(wildcard *.c))
BONUS	= $(wildcard *_bonus.c)
HEADERS	= libft.h
OBJS	= ${SRCS:.c=.o}
NAME	= libft.a
BOBJS	= ${BONUS:.c=.o}

all: ${NAME}

$(NAME): $(OBJS)
	@ar rcs $(NAME) $^
	@echo "libft.a ready"

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS} ${BOBJS}

fclean: clean
	rm -f ${NAME}

re:	fclean all

bonus: $(NAME) $(BOBJS)
	ar rcs $(NAME) $(BOBJS)
	@echo "libft.a (bonus) ready"
