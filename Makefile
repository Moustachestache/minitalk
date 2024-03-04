# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjochum <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 11:43:10 by mjochum           #+#    #+#              #
#    Updated: 2023/06/09 18:27:53 by mjochum          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =	server

NAME_CLI =	client

SRCS_PRINTF =	printf/ft_printf.c printf/ft_functions.c \
		printf/ft_puthex.c printf/ft_putnbr.c

SRCS_LIBFT =	lib/ft_calloc.c lib/ft_strlen.c lib/ft_strjoin.c \
		lib/ft_atoi.c lib/ft_strdup.c

SRCS_SRV =	server.c

SRCS_CLI =	client.c

SRCS_UTILS =	utilities.c $(SRCS_LIBFT) $(SRCS_PRINTF)

OBJS_U =	$(SRCS_UTILS:.c=.o)

OBJS_S =	$(SRCS_SRV:.c=.o)

OBJS_C =	$(SRCS_CLI:.c=.o)

CC =		clang
CFLAGS =	-Wall -Wextra -Werror

$(NAME):	$(OBJS_U) $(OBJS_S)
		$(CC) $(CFLAGS) $(OBJS_S) $(OBJS_U) -o $(NAME)

$(NAME_CLI):	$(OBJS_U) $(OBJS_C)
		$(CC) $(CFLAGS) $(OBJS_C) $(OBJS_U) -o $(NAME_CLI)

all:		$(NAME) $(NAME_CLI)

clean:		
		rm -f $(OBJS_U) $(OBJS_S) $(OBJS_C)

fclean:		clean
		rm -f $(NAME_CLI) $(NAME)

re:		fclean all
