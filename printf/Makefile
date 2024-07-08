# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 01:17:38 by shachan           #+#    #+#              #
#    Updated: 2024/07/06 20:06:18 by shachan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = libftprintf.a

# SOURCES = \
# 	ft_format_functions.c ft_printf.c \

# OBJECTS = $(SOURCES:.c=.o)

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror

# all: $(NAME)

# $(NAME): $(OBJECTS)
# 	$(AR) -r $@ $?

# $(OBJECTS): %.o: %.c
# 	$(CC) -c $(CFLAGS) $?

# clean:
# 	rm -f $(OBJECTS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re 

NAME = libftprintf.a

SOURCES = ft_printf.c ft_format_functions.c

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