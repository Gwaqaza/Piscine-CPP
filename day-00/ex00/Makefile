# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmahele <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/04 17:04:39 by pmahele           #+#    #+#              #
#    Updated: 2018/06/05 10:11:32 by pmahele          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC = megaphone.cpp

FLAGS = -Wall -Werror -Wextra

G++ = g++

all = $(NAME)

$(NAME):
	$(G++) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o $(NAME)
