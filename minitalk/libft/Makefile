# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 08:54:50 by ansilva-          #+#    #+#              #
#    Updated: 2022/02/28 13:38:20 by ansilva-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isalpha ft_isdigit ft_isalnum ft_isascii\
	  ft_isprint ft_strlen ft_memset ft_bzero\
	  ft_memcpy ft_memmove ft_strlcpy ft_strlcat\
	  ft_toupper ft_tolower ft_strchr ft_strrchr\
	  ft_strncmp ft_memchr ft_memcmp ft_strnstr\
	  ft_atoi ft_calloc ft_strdup ft_substr\
	  ft_strjoin ft_strtrim ft_split ft_itoa\
	  ft_strmapi ft_striteri ft_putchar_fd\
	  ft_putstr_fd ft_putendl_fd ft_putnbr_fd\

BONUS = ft_lstnew ft_lstadd_front ft_lstsize\
		 ft_lstlast ft_lstadd_back ft_lstdelone\
		 ft_lstclear ft_lstiter ft_lstmap\

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I libft.h
AR = ar rc

all: $(NAME)

$(NAME): $(SRC:=.o)
	$(AR) $(NAME) $(SRC:=.o)

bonus: $(NAME) $(BONUS:=.o)
	$(AR) $(NAME) $(BONUS:=.o)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRC:=.o) $(BONUS:=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re bonus
