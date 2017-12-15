# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 08:50:18 by llopez            #+#    #+#              #
#    Updated: 2017/12/15 16:57:53 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C libft/
	gcc main.c get_next_line.c -Llibft -lft -Wall -Werror -Wextra

clean:
	make -C libft/ clean

fclean: clean

re: fclean all
