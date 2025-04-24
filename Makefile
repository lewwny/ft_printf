# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 20:35:06 by lenygarcia        #+#    #+#              #
#    Updated: 2025/04/24 19:56:00 by lenygarcia       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC              = cc -g
CFLAGS          = -Wall -Wextra -Werror -Ilibft/includes -Iincludes
SRCS            = srcs/ft_printf.c srcs/ft_putchari.c srcs/ft_putnbrhexmaj.c srcs/ft_putnbrhexmin.c srcs/ft_putnbri.c srcs/ft_putnbrui.c srcs/ft_putptr.c srcs/ft_putstri.c
OBJS            = $(SRCS:.c=.o)
NAME            = libftprintf.a
LIBFT_PATH      = ./libft
LIBFT           = $(LIBFT_PATH)/libft.a
TEMP_DIR        = .temp_objs

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH)
	@rm -rf $(TEMP_DIR)
	@mkdir $(TEMP_DIR)
	@cd $(TEMP_DIR) && ar x ../$(LIBFT)
	@cp $(OBJS) $(TEMP_DIR)
	@cd $(TEMP_DIR) && ar rcs ../$(NAME) *.o
	@rm -rf $(TEMP_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) all

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
