# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/23 08:02:12 by texenber          #+#    #+#              #
#    Updated: 2025/10/28 09:25:02 by texenber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

#ingredients
SRC_DIR := src
OBJ_DIR := obj
SRCS :=	\
	pipex.c
SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR := include/libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

PRINTF_DIR := include/ft_printf
PRINTF_LIB := $(PRINTF_DIR)/libftprintf.a

CC := cc
CFLAGS := -g -Wall -Werror -Wextra
CFLAGS += -I$(LIBFT_DIR) -I$(PRINTF_DIR)

#utensils
RM := rm -f 
LM := make -C 
MAKEFLAGS += --no-print-directory
DIR_DUP = mkdir -p $(@D)

#recipe
all: $(LIBFT_LIB) $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $@
	$(info CREATED $(NAME))

$(LIBFT_LIB):
	$(LM) $(LIBFT_DIR)

$(PRINTF_LIB):
	$(LM) $(PRINTF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS)
	$(LM) $(LIBFT_DIR) clean
	$(LM) $(PRINTF_DIR) clean
	$(info sweep sweep)

fclean: clean
	$(RM) $(NAME)
	$(LM) $(LIBFT_DIR) fclean
	$(LM) $(PRINTF_DIR) fclean
	rm -rf $(OBJ_DIR)
	$(info SWEEP SWEEP)

re:
	$(MAKE) fclean
	$(MAKE) all

#special
.PHONY: clean fclean re
.SILENT: