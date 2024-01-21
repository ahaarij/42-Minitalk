# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 08:51:01 by ahaarij           #+#    #+#              #
#    Updated: 2023/12/11 09:48:04 by ahaarij          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printchar.c ft_printhex.c ft_printnbr.c ft_printptr.c ft_printstr.c ft_printuint.c ft_printf.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

OBJS = $(SRCS:.c=.o)

AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = all clean fclean re