# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 13:24:06 by bkuksa            #+#    #+#              #
#    Updated: 2018/10/31 13:30:52 by bkuksa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = *.c

OBJECTS = *.o

INCL = includes/

HEADER = -I

FLAGS = -c -Wall -Wextra -Werror 

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(HEADER) $(INCL) $(FILES)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
