# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micheng <micheng@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 16:17:18 by micheng           #+#    #+#              #
#    Updated: 2023/08/12 03:35:21 by micheng          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush_01
CC = gcc -g3 -fsanitize=address
INCLUDES = -Iincludes -Ilibft
LIBFT = -Llibft -lft
RM = rm -rf
OBJ_DIR = obj

SRCS = $(wildcard srcs/*.c)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(LIBFT) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re