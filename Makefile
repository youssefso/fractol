# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/09 20:18:45 by ymoukhli          #+#    #+#              #
#    Updated: 2019/03/13 18:55:09 by ymoukhli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C libft
	gcc *.c -o fractol libft/libft.a -I minilibix_macos -L minilibx_macos -lmlx -framework Opengl -framework appkit -pthread

clean:
	make clean -C libft

fclean:
	make fclean -C libft
	rm -rf fractol

re : fclean all
