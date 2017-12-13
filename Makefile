# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 07:40:38 by mmpofu            #+#    #+#              #
#    Updated: 2017/12/13 11:41:21 by mmpofu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

SRCS = main.c error.c read_and_store.c \
	   save.c search_and_destroy.c \
	   store_links.c

LIB = -L libft -lft

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	clang $(FLAGS) $(SRCS) $(LIB) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:		fclean all
