# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 21:40:45 by ialousse          #+#    #+#              #
#    Updated: 2023/03/15 17:22:34 by ialousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = includes

SRCS =	srcs/main.c \
		srcs/chuck.c \
		srcs/stack.c \
		commande/ft_push.c \
		commande/ft_reverse_rotate.c \
		commande/ft_rotate.c \
		commande/ft_swap.c \
		get_nbr/get_g.c \
		get_nbr/get.c \
		libft/libutils1.c \
		libft/libutils.c \
		push/push_to.c \
		push/push.c \
		sort/sort_nbr.c \
		sort/sort.c \
		sort/sort1.c

OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
