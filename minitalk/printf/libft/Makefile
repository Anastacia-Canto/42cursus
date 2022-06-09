# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 08:54:50 by ansilva-          #+#    #+#              #
#    Updated: 2022/03/10 10:26:45 by ansilva-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_strlen ft_itoa ft_putchar ft_putstr

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I libft.h
AR = ar rc

all: $(NAME)

$(NAME): $(SRC:=.o)
	$(AR) $(NAME) $(SRC:=.o)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRC:=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
