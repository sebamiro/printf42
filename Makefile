# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seba <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 16:37:30 by seba              #+#    #+#              #
#    Updated: 2022/08/22 15:04:46 by seba             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c puthexnbr.c putptr.c handletype.c putchar.c putnbr.c \
		putstr.c

OBJS	= $(SRCS:.c=.o)

CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror -I.

NAME	= libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(NAME) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)
