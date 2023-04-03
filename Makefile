# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 15:57:04 by jpelaez-          #+#    #+#              #
#    Updated: 2023/04/03 14:24:17 by jpelaez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRC_C = client.c 
SRC_S = server.c

OBJECT_C = $(SRC_C:.c=.o)
OBJECT_S = $(SRC_S:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

HEADER = minitalk.h
LIBFT_HEADER = ./libft/libft.h
PRINTF_HEADER = ./ft_printf/ft_printf.h

LFLAGS = -L $(LIBFT_DIR) -L$(PRINTF_DIR) -l ft -l ftprintf
IFLAGS = -I $(HEADER)
FLAGS = -Wall -Wextra -Werror

CC = cc
MAKE = make

all: $(SERVER) $(CLIENT) $(LIBFT) $(PRINTF)

$(SERVER): $(OBJECT_S) 
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(FLAGS) $(IFLAGS) $(OBJECT_S) $(LIBFT) $(PRINTF) -o $(SERVER) 

$(CLIENT): $(OBJECT_C) 
	$(CC) $(FLAGS) $(IFLAGS) $(OBJECT_C) $(LIBFT) $(PRINTF) -o $(CLIENT) 

clean:
	rm -f $(OBJECT_C) $(OBJECT_S) 

fclean: clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(MAKE) -C $(PRINTF_DIR) fclean
	   	rm -f $(SERVER)
	   	rm -f $(CLIENT)

re: fclean all

.PHONY: all re fclean clean