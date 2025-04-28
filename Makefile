# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 20:35:06 by lenygarcia        #+#    #+#              #
#    Updated: 2025/04/28 08:23:00 by lengarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS		= -Wall -Wextra -Werror -g -Ilibft/includes -Iincludes
SRCS		= srcs/ft_printf.c srcs/ft_putchari.c srcs/ft_putnbrhexmaj.c srcs/ft_putnbrhexmin.c \
		srcs/ft_putnbri.c srcs/ft_putnbrui.c srcs/ft_putptr.c srcs/ft_putstri.c
OBJS		= $(SRCS:.c=.o)
NAME		= libftprintf.a
LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@cp $(LIBFT) .
	@ar rcs $(NAME) $(OBJS) libft.a
	@rm -f libft.a

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re

