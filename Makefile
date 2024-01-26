# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 12:59:39 by ahaarij           #+#    #+#              #
#    Updated: 2024/01/23 20:28:25 by ahaarij          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server

CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -g3 -fsanitize=address
RM = rm -rf

LIBFT = ./libft/libft.a

SRC_C = srcs/client.c
OBJ_C = $(SRC_C:%.c=%.o)

SRC_S = srcs/server.c
OBJ_S = $(SRC_S:%.c=%.o)

# Time for the rules!

all: $(NAMES) $(NAMEC)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAMES): $(OBJ_S) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o server
	
$(NAMEC): $(OBJ_C) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_C) $(LIBFT) -o client

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJ_S) $(OBJ_C)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAMES) $(NAMEC)

re: fclean all