# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 15:57:04 by jpelaez-          #+#    #+#              #
#    Updated: 2023/04/04 18:24:15 by jpelaez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client

SRC_C = client.c 
SRC_S = server.c

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

HEADER = minitalk.h

IFLAGS = -I $(HEADER)
FLAGS = -Wall -Wextra -Werror

CC = cc
MAKE = make

all: $(SERVER) $(CLIENT) $(LIBFT) $(PRINTF)

$(NAME):

$(SERVER): $(SRC_S)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(FLAGS) $(IFLAGS) $(SRC_S) $(LIBFT) $(PRINTF) -o $(SERVER) 

$(CLIENT): $(SRC_C)
	$(CC) $(FLAGS) $(IFLAGS) $(SRC_C) $(LIBFT) $(PRINTF) -o $(CLIENT) 

clean:
	rm -f $(SERVER) $(CLIENT) 

fclean: clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(MAKE) -C $(PRINTF_DIR) fclean
	   	rm -f $(SERVER)
	   	rm -f $(CLIENT)

re: fclean all

.PHONY: all re fclean clean