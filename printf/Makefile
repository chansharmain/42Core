# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shachan <shachan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 01:17:38 by shachan           #+#    #+#              #
#    Updated: 2024/07/13 19:22:48 by shachan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c ft_format_functions.c ft_format_functions2.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): %.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -rf $(OBJECTS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re