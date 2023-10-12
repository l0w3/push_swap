# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 14:47:35 by groman-l          #+#    #+#              #
#    Updated: 2023/10/12 16:45:09 by alrodri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~VARIABLES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
NAME = push_swap
CC = gcc
RM = rm -rf
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror -g

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SORUCES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
SRC = parse.c push_swap.c init.c push.c rev_rotate.c swap.c utils.c 
LIBFT = ./libft/
FTPRINTF = ./ft_printf/
L_SRC = ./src
L_LIB = ./libft/libft.a
L_FTPRINTF = ./ft_printf/libftprintf.a
INC =   -I ./inc/\
        -I ./libft/\
		-I ./ft_printf/\

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DIRECTORIES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
D_OBJ = $(L_SRC)/obj
OBJ = $(addprefix $(D_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRC:.c=.d))

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAKE RULES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
all: dir $(NAME)

-include $(DEP)

dir:
	make -C  $(LIBFT) --no-print-directory
	mkdir -p $(D_OBJ)

$(D_OBJ)/%.o: $(L_SRC)/%.c
	$(CC) -MMD $(FLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(L_LIB) -o $(NAME) $(INC)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~futura no barra de carga~~~~~~~~~~~~~~~~~~~#

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CLEAN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
.PHONY: clean fclean re

fclean: clean
	$(RM) $(NAME) $(NAME)
	make fclean -C $(LIBFT) --no-print-directory

clean:
	$(RM) $(D_OBJ)
	make clean -C $(LIBFT) --no-print-directory

re: fclean all
.SILENT: