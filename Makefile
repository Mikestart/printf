# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoledan <mtoledan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 18:35:44 by mtoledan          #+#    #+#              #
#    Updated: 2023/05/05 16:38:40 by mtoledan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =  libft_help.c \
		ft_printf.c \
		utils.c

OBJS = ${SRCS:.c=.o}
RM = rm -f

all: ${NAME}

.c.o:
	@echo "Compiling ..."
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs $(NAME) $(OBJS) 
#	${CC} -o ${NAME} ${OBJS} 
	@echo "Compilation OK ! Library successfully created.\n"

clean:
	${RM} ${OBJS}
	@echo ".o files removed\n"

fclean: clean
	${RM} ${NAME}
	@echo ".a removed\n"

re: fclean all
	@echo "(remake)\n"
