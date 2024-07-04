# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 19:16:47 by jschmitz          #+#    #+#              #
#    Updated: 2024/07/04 19:30:57 by jschmitz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

SRCS = ft_printf.c ft_putchar_ptr.c ft_putnbr_hex_ptr.c \
	ft_putnbr_ptr.c ft_putstr_ptr.c

OBJ = $(SRCS:.c=.o)

HEADER_DIR = ./Headerfiles

HEADER = $(HEADER_DIR)/*.h

CFLAGS = -Wall -Wextra -Werror -I$(HEADER_DIR)

RM = rm -f

AR = ar rcs

all : $(NAME)

$(NAME) : $(OBJ)
	${AR} $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJBONUS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJBONUS)
	${AR} ${NAME} ${OBJBONUS}

.PHONY: re clean fclean all bonus
