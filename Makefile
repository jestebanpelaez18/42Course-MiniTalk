# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 15:57:04 by jpelaez-          #+#    #+#              #
#    Updated: 2023/02/06 18:32:45 by jpelaez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = serve
NAME_C = client

SRC = client.c server.c\

LIBFT =	./libft
PRINTF = ./ft_printf

HEADER = -c -I minitalk.h
LIBFT_HEADER = ./libft/libft.h
PRINTF_HEADER = ./ft_printf/ft_printf.h

FLAGS = -Wall -Wextra -Werror
CC = cc -c

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) $(HEADER) 
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME) 
	
clean:
	rm -f $(OBJECT) $(OBJECTB)

fclean: clean
	   rm -f $(NAME)

re: fclean all