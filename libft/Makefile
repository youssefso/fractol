# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 17:39:38 by ymoukhli          #+#    #+#              #
#    Updated: 2018/12/11 05:23:14 by ymoukhli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = *.c
files = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) -I Includes 
	ar rc $(NAME) $(files)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
