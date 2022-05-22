# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 11:27:43 by gyumpark          #+#    #+#              #
#    Updated: 2022/05/22 20:08:36 by gyumpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = ./main.c ./ft_error.c ./ft_read.c ./Libft/ft_atoi.c ./Libft/ft_isdigit.c ./Libft/ft_isalpha.c ./Libft/ft_split.c get_next_line.c ./Libft/ft_calloc.c ./Libft/ft_strchr.c ./Libft/ft_strjoin.c ./Libft/ft_strlen.c ./Libft/ft_bzero.c ./Libft/ft_memset.c ./ft_draw.c ./ft_max.c ./ft_mod.c
OBJS = $(SRCS:%.c=%.o)

CC = cc
CFLAG = -Wall -Wextra -Werror
\CFLAG = -fsanitize=address -g3

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(SRCS) minilibx_macos/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.dSYM
	

re: fclean all

.PHONY: all clean fclean re
