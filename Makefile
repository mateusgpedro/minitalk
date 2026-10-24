# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 12:23:07 by maguimar          #+#    #+#              #
#    Updated: 2026/10/24 02:41:00 by maguimar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I./libft
RM = rm -rf

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CLIENT = client
SERVER = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

SRC_CLIENT = src/mandatory/client.c
OBJ_CLIENT = $(SRC_CLIENT:%.c=%.o)

SRC_SERVER = src/mandatory/server.c
OBJ_SERVER = $(SRC_SERVER:%.c=%.o)

SRC_CLIENT_BONUS = src/bonus/client_bonus.c
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:%.c=%.o)

SRC_SERVER_BONUS = src/bonus/server_bonus.c
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:%.c=%.o)

all: $(CLIENT) $(SERVER)

$(LIBFT):
	@$(MAKE) bonus -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(LIBFT) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(LIBFT) -o $(SERVER_BONUS)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
