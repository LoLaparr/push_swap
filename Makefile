# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 14:52:45 by lolaparr          #+#    #+#              #
#    Updated: 2023/03/22 16:02:13 by louislaparr      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
SRC_DIR		:= src
BUILD_DIR:= .build
SRCS		:=  push_swap.c \
				utils.c \
				parsing.c \
				push.c \
				swap.c \
				rotate.c \
				reverse_rotate.c \
				case_3.c \
				case_5.c \
				cost.c \
				move.c \
				position.c \
				sort.c \
				free.c

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc -g3
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -MMD -MP -I include
RM			:= rm -rf
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)
LIBRARIES	:= -L libft -lft
INCLUDES	:= -Ilibft/include

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(OBJS) $(LIBRARIES) -o $(NAME)
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

re: clean all
