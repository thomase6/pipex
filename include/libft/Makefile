# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 14:29:16 by texenber          #+#    #+#              #
#    Updated: 2025/09/26 10:09:01 by texenber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

#ingredients
SRC_DIR := src
OBJ_DIR := obj
SRCS := \
	ft_abs.c \
	ft_atof.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_is_space.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strmapi.c \
	ft_substr.c \
	ft_strtrim.c \
	ft_split.c
SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror

#utensils
RM := rm -f
LM := make -C
MAKEFLAGS += --no-print-directory
DIR_DUP = mkdir -p $(@D)

#recipe
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)
	rm -rf $(OBJ_DIR)
	
re:
	$(MAKE) fclean
	$(MAKE) all
	
#special
.PHONY: clean fclean re
.SILENT: