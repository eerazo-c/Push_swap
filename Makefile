# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 12:37:12 by eerazo-c          #+#    #+#              #
#    Updated: 2023/12/13 21:04:08 by eerazo-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap.a
SOURCES =

INCLUDE = -I

HEADER = push_swap.h

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(INCLUDE)$(HEADER) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
