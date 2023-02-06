# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 17:18:29 by jpelaez-          #+#    #+#              #
#    Updated: 2022/12/12 18:01:47 by jpelaez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c ft_helpers.c ft_string.c ft_hexadecimal.c ft_numbers.c ft_unsignedint.c ft_pointer.c\

HEADER = -c -I ft_printf.h 

FLAGS = -Wall -Wextra -Werror

OBJECT = 	ft_printf.o ft_helpers.o ft_string.o ft_hexadecimal.o ft_numbers.o ft_unsignedint.o ft_pointer.o\

all: $(NAME)

$(NAME):
	cc -c $(FLAGS) $(SRC) $(HEADER) 
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME) 
	
clean:
	rm -f $(OBJECT) $(OBJECTB)

fclean: clean
	   rm -f $(NAME)

re: fclean all