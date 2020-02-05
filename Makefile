# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 15:27:04 by bkuksa            #+#    #+#              #
#    Updated: 2019/03/28 14:00:48 by bkuksa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

GCC = clang
OBJS_DIR = .libftprintf_objects
FLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

LIB_FOLDER = libft/
LIB_INCS =	libft.h
LIB_SRCS = 	ft_atoi.c\
                ft_putnbr.c\
                ft_putchar.c\
                ft_putstr.c\
                ft_strlen.c\
                ft_memalloc.c\
                ft_memcpy.c\
                ft_isdigit.c\
                ft_memset.c\
                ft_strchr.c\
                ft_itoa.c\
                ft_strnew.c\
                ft_strcpy.c\
                ft_strcat.c\
                ft_strdel.c\
                ft_strncpy.c\
                ft_strjoin.c\
                ft_strcmp.c\
                ft_memdel.c
LIB_OBJS = $(LIB_SRCS:%.c=$(LIB_OBJS_DIR)/%.o)
LIB_OBJS_DIR = $(OBJS_DIR)

PRINT_FOLDER = print/
PRINT_INCS =	ft_printf.h
PRINT_SRCS =	format.c\
                ft_printf.c\
                tipe.c\
                valid_bog.c\
                tipe_2.c\
                printf_f.c\
                app.c\
                ft_zero_minus.c\
                ft_unicod.c\
                mod.c
PRINT_OBJS = $(PRINT_SRCS:%.c=$(PRINT_OBJS_DIR)/%.o)
PRINT_OBJS_DIR = $(OBJS_DIR)

all: $(NAME)

$(NAME): $(LIB_OBJS) $(PRINT_OBJS)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

$(LIB_OBJS_DIR)/%.o: $(LIB_FOLDER)%.c
	@mkdir -p $(LIB_OBJS_DIR)
	@$(GCC) $(FLAGS) -c $< $(addprefix -I.,$(addprefix $(LIB_FOLDER),$(LIB_INCS))) -o $@

$(PRINT_OBJS_DIR)/%.o: $(PRINT_FOLDER)%.c
	@mkdir -p $(PRINT_OBJS_DIR)
	@$(GCC) $(FLAGS) -c $< $(addprefix -I.,$(addprefix $(PRINT_FOLDER),$(PRINT_INCS))) -o $@

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

run:
	@$(GCC) $(FLAGS) main.c libftprintf.a | cat -e
	@./a.out || true
	@$(RM) ./a.out

run_warn:
	@$(CC) main.c libftprintf.a
	@./a.out || true
	@$(RM) ./a.out

.PHONY: all clean fclean re run run_warn test rmt
