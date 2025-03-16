# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 20:35:06 by lenygarcia        #+#    #+#              #
#    Updated: 2025/03/15 20:22:46 by lenygarcia       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC              = cc -g
CFLAGS          = -Wall -Wextra -Werror -Ilibft/includes -Iincludes
SRCS            = $(wildcard srcs/*.c)
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
	@echo "$(NAME) is ready"

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
