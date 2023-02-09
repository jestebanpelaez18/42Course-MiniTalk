# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 15:57:04 by jpelaez-          #+#    #+#              #
#    Updated: 2023/02/09 18:07:39 by jpelaez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRC_C = client.c 
SRC_S = server.c

OBJECT_C = $(SRC_C:.c=.o)
OBJECT_S = $(SRC_S:.c=.o)

LIBFT_DIR = ./libft 
PRINTF_DIR = ./ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

HEADER = minitalk.h
LIBFT_HEADER = ./libft/libft.h
PRINTF_HEADER = ./ft_printf/ft_printf.h

LFLAGS = -L $(LIBFT_DIR) -L$(PRINTF_DIR) -l ft -l ftprintf
IFLAGS = -I $(HEADER) -I $(LIBFT_HEADER) -I $(PRINTF_HEADER)
FLAGS = -Wall -Wextra -Werror

CC = clang
MAKE = make

all: $(SERVER) $(CLIENT) $(PRINTF) $(LIBFT)

$(SERVER): $(OBJECT_S) $(LIBFT) $(PRINTF)
	$(CC) $(OBJECT_S) -o $(SERVER) $(LFLAGS)

$(CLIENT): $(OBJECT_C) $(LIBFT) $(PRINTF)
	$(CC) $(OBJECT_C) -o $(CLIENT) $(LFLAGS)

$(OBJECT_S)%.o: $(SRC_S)
	$(CC) $(FLAGS) $(SRC_S) $(IFLAGS) -c -o $@ $< 

$(OBJECT_C)%.o: $(SRC_C)
	$(CC) $(FLAGS) $(SRC_C) $(IFLAGS) -c -o $@ $<

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
		$(MAKE) -C $(PRINTF_DIR)
		
clean:
	rm -f $(OBJECT_C) $(OBJECT_S) 

fclean: clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(MAKE) -C $(PRINTF_DIR) fclean
	   	rm -f $(SERVER)
	   	rm -f $(CLIENT)

re: fclean all

.PHONY: all re fclean clean