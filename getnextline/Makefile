# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 00:21:42 by shachan           #+#    #+#              #
#    Updated: 2024/08/22 01:17:07 by shachan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a 

SOURCES = get_next_line.c get_next_line_utils.c 

BSOURCES = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

# CC = cc
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

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $@ $?

bonus: $(OBJECTS) $(BOBJECTS)
	$(AR) $(NAME) $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
