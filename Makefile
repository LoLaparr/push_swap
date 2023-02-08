# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 14:52:45 by lolaparr          #+#    #+#              #
#    Updated: 2023/02/06 11:45:59 by lolaparr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
SRC_DIR		:= src
BUILD_DIR:= .build
SRCS		:= make_tab.c \
			parsing.c \
			recurcive.c \
			get_map.c \
			main.c \
			move.c \
			utils.c \
			free_all.c

PATH_MLX = ./mlx-linux/

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc -g3
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -MMD -MP -I include
RM			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)
LIBRARIES	:= -L libft -lft
INCLUDES	:= -Ilibft/include
MLX_LIBS	:= -L $(PATH_MLX) -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) -g $(OBJS) $(LIBRARIES) $(MLX_LIBS) -o $(NAME)
	$(info CREATED $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean
