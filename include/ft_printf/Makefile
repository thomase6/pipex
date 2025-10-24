# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 10:42:43 by texenber          #+#    #+#              #
#    Updated: 2025/09/29 17:14:02 by texenber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS1 = ft_printf.c\
		count_putchar.c\
		count_putstr.c\
		putupperhex.c\
		putlowerhex.c\
		putaddresshex.c\
		putaddress.c\
		count_putuint.c\
		count_putnbr.c\

NAME = libftprintf.a
LIBC = ar rcs
CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS1:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(LIBC) $(NAME) $(OBJS)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
