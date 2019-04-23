/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:46:13 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/04/21 17:52:51 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_light_pixel(t_init *v, int x, int y, int n)
{
	int i;

	if (x >= WIDTH || x < 0 || y < 0 || y >= HIGHT)
		return ;
	i = 4 * x + 4 * y * WIDTH;
	if (n == v->iteration)
	{
		v->img_str[i] = (unsigned char)(0);
		v->img_str[i + 1] = (unsigned char)(0);
		v->img_str[i + 2] = (unsigned char)(0);
		return ;
	}
	v->img_str[i] = (unsigned char)(((int)n * 3 + v->cl_0) % 255);
	v->img_str[i + 1] = (unsigned char)(((int)n * 1092 + v->cl_1) % 255);
	v->img_str[i + 2] = (unsigned char)(((int)n * 3 + v->cl_2) % 255);
}

void	ft_mlx_o_event(t_init *init)
{
	int bpp;
	int s_l;
	int endian;

	init->init = mlx_init();
	init->win = mlx_new_window(init->init, WIDTH, HIGHT, "fractal");
	init->img = mlx_new_image(init->init, WIDTH, HIGHT);
	init->img_str = (unsigned char *)mlx_get_data_addr(init->img,
			&bpp, &s_l, &endian);
	mlx_hook(init->win, 2, 1, t_kees, init);
	mlx_mouse_hook(init->win, mouse_press, init);
	mlx_hook(init->win, 6, 1, mouse_move, init);
}

void	ft_initialisation(t_init *init)
{
	init->mod_move = 0;
	init->zoom = 1.4;
	init->mod_mouse = 0;
	init->iteration = 50;
	init->move_hz = 0;
	init->move_vr = 0;
	init->cl_0 = 0;
	init->cl_2 = 0;
	init->cl_1 = 0;
	init->start_x = -2;
	init->start_y = -1;
	init->end_x = 1;
	init->end_y = 1;
	init->julia_c_x = -0.75;
	init->julia_c_y = 0.11;
}

void	ft_else(t_init *init)
{
	ft_putstr("choose one of the three :\033[0;34m mandelbrot, ");
	ft_putstr("\033[0;32mjulia, \033[0;31mburn\n");
	free(init);
	exit(-1);
}

int		main(int ac, char **av)
{
	t_init	*init;
	int		i;

	if (ac == 2)
	{
		init = (t_init *)malloc(sizeof(t_init));
		ft_mlx_o_event(init);
		ft_initialisation(init);
		if (ft_strcmp(av[1], "mandelbrot") == 0)
			ft_pthread_mandel(init);
		else if (ft_strcmp(av[1], "julia") == 0)
			ft_pthread_julia(init);
		else if (ft_strcmp(av[1], "burn") == 0)
			ft_pthread_nova(init);
		else
			ft_else(init);
		mlx_put_image_to_window(init->init, init->win, init->img, 0, 0);
		mlx_loop(init->init);
	}
	else
	{
		ft_putstr("choose one (and only one) of the three : \033[0;34m");
		ft_putstr("mandelbrot, \033[0;32mjulia, \033[0;31mburn\n");
	}
	return (0);
}
