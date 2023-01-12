# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 12:23:07 by maguimar          #+#    #+#              #
#    Updated: 2023/01/12 15:40:55 by maguimar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = ./libft/libft.a

CLIENT = client
SERVER = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

SRC_CLIENT = src/client.c
OBJ_CLIENT = $(SRC_CLIENT:%.c=%.o)

SRC_SERVER = src/server.c
OBJ_SERVER = $(SRC_SERVER:%.c=%.o)

SRC_CLIENT_BONUS = src/client_bonus.c
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:%.c=%.o)

SRC_SERVER_BONUS = src/server_bonus.c
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:%.c=%.o)

all: $(NAME)

$(LIBFT):
		make bonus -C ./libft

$(NAME) : $(OBJ_CLIENT) $(OBJ_SERVER) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)
		@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)

bonus: $(NAME) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(LIBFT) -o $(CLIENT_BONUS)
		@$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(LIBFT) -o $(SERVER_BONUS)

clean:
		@$(MAKE) clean -C ./libft
		@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)

fclean: clean
		@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
		@$(RM) $(LIBFT)

re: fclean all
