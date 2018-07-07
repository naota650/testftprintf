# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmartine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/03 18:41:20 by lmartine          #+#    #+#              #
#    Updated: 2018/07/07 16:31:52 by lmartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = cast_var.c int_conv.c str_conv.c ft_printf.c handle_var.c parse.c libfunc1.c libfunc2.c strings.c
OBJS = cast_var.o int_conv.o str_conv.o ft_printf.o handle_var.o parse.o libfunc1.o libfunc2.o strings.o

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
