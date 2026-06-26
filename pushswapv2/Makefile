# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: addufour <addufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/20 18:00:00 by lchehbi           #+#    #+#              #
#    Updated: 2026/06/26 11:35:03 by addufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -I.

SRC		= main.c \
		  error.c \
		  stack_1.c \
		  stack_2.c \
		  parse_utils.c \
		  parse.c \
		  instr_utils.c \
		  instr_swap.c \
		  instr_push.c \
		  instr_rotate.c \
		  instr_rrotate.c \
		  sort_small.c \
		  sort_medium.c \
		  sort_medium2.c \
		  ft_utils.c \
		  adaptive.c \
		  bench_1.c \
		  bench_2.c \
		  chunksort.c \
		  disorder_metric.c \
		  flags.c \
		  mini_sort_utils.c \
		  mini_sort.c \
		  nearly_sorted.c \
		  radix_utils.c \
		  radix.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) test_push_swap

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(filter-out src/main.o, $(OBJ))
	$(CC) $(CFLAGS) $(filter-out src/main.o, $(OBJ)) tests/test_utils.c tests/test_push_swap.c -o test_push_swap
	./test_push_swap

.PHONY: all clean fclean re test
