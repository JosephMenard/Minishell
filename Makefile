# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 11:43:29 by mianni            #+#    #+#              #
#    Updated: 2024/10/13 17:03:07 by jmenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
INCLUDES = minishell.h

SRC = ./minishell_utils/minishell.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft
	
all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./libft

libft_clean:
	$(MAKE) clean -C ./libft
	
libft_fclean:
	$(MAKE) fclean -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -L$(LIBFT_PATH) -lft -lreadline $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

clean: libft_clean
	rm -f $(OBJ)

fclean: libft_fclean clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re LIBFT libft_clean libft_fclean
