# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjochum <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 14:15:31 by mjochum           #+#    #+#              #
#    Updated: 2023/03/29 12:23:16 by mjochum          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SOURCES =	ft_printf.c ft_functions.c ft_puthex.c ft_putnbr.c

OBJECTS =	$(SOURCES:.c=.o)

CC =		clang
CFLAGS =	-Wall -Wextra -Werror

$(NAME): $(OBJECTS)
	ar cr $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re: fclean all
