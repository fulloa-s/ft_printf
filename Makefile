# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 09:02:50 by fulloa-s          #+#    #+#              #
#    Updated: 2021/02/09 12:20:21 by fulloa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			ft_putstr.c \
			ft_decimal.c \
			ft_printf_utils.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_unsigned.c \
			ft_hexadecimal.c \
			ft_address.c \
			ft_putchar.c \
			ft_precision.c \
			ft_flag.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	= 	-Wall -Wextra -Werror

RM		=	rm -f

.c.o		:
				$(CC) $(CFLAGS) -c $<

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME) 

re			:	fclean all

.PHONY		:	all clean fclean re
