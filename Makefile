# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 12:37:12 by eerazo-c          #+#    #+#              #
#    Updated: 2024/01/31 18:58:52 by eerazo-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap
SOURCES = Src/push_swap.c Src/checkers.c Src/utils.c \
		  Src/swap_stack.c Src/pwap_stack.c Src/rotate.c \
		  Src/rev_rot.c Src/algrt.c Src/aux.c Src/aux1.c \

LIBFT_PATH = library/libft
LIB_PRINTF_PATH = library/printf

LIBFT_H = $(LIBFT_PATH)/libft.h
LIB_PRINTF_H = $(LIB_PRINTF_PATH)/ft_printf.h

HEADER_PATH = Inc

HEADER = $(HEADER_PATH)/push_swap.h

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(HEADER)

all: lib print $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_H) $(LIB_PRINTF_H) $(HEADER)
	$(CC) $(CFLAGS) $(LIBFT_PATH)/libft.a $(LIB_PRINTF_PATH)/libftprintf.a $(SOURCES) -o $@

lib: 
	make -C $(LIBFT_PATH)

print:
	make -C $(LIB_PRINTF_PATH)
	
clean:
	rm -rf $(OBJECTS)
	make clean -C $(LIBFT_PATH)
	make clean -C $(LIB_PRINTF_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(LIB_PRINTF_PATH)

re: fclean all

.PHONY: all clean fclean re lib print
