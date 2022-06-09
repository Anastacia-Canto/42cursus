# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 16:26:13 by ansilva-          #+#    #+#              #
#    Updated: 2022/06/07 15:53:11 by ansilva-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
SERVER = server
CLIENT = client
SRC = 	printf/ft_printf.c\
		printf/ft_put_base_hex.c\
		printf/ft_put_base_pointer.c\
		printf/ft_put_base.c\
		printf/ft_put_di.c\
		printf/ft_put_hex.c\
		printf/ft_put_pointer.c\
		printf/ft_put_u.c\
		printf/libft/ft_itoa.c\
		printf/libft/ft_putchar.c\
		printf/libft/ft_putstr.c\
		printf/libft/ft_strlen.c\
		libft/ft_atoi.c\
		libft/ft_isdigit.c\
		libft/ft_memset.c
		
PRINTF = printf/libftprintf.a
PRINTF_PATH = ./printf

LIBFT = libft/libft.a
LIBFT_PATH = ./libft

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I.

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT) 

$(SERVER): $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SRC) $(SERVER).c -o $(SERVER)

$(CLIENT): 
	$(CC) $(CFLAGS) $(SRC) $(CLIENT).c -o $(CLIENT)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(PRINTF):
	make -C $(PRINTF_PATH)

clean:
	$(RM) $(CLIENT) $(SERVER)

fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(NAME)

re: fclean all

.PHONY: all clean fclean re
