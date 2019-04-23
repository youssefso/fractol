/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kye_bind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 13:27:21 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/04/17 17:04:02 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		mouse_move(int x, int y, t_init *init)
{
	double mouse_x;
	double mouse_y;

	if (init->what == 1 && init->set == 1)
	{
		init->julia_c_x = ft_map_x(init, x);
		init->julia_c_y = ft_map_y(init, y);
		ft_pthread_julia(init);
		mlx_put_image_to_window(init->init, init->win, init->img, 0, 0);
	}
	return (0);
}

void	ft_t_kees(int key, t_init *init)
{
	if (key == 15)
		init->iteration += 10;
	if (key == 3)
		init->iteration -= 10;
	if (key == 12)
		init->cl_0 += 10;
	if (key == 0)
		init->cl_0 -= 10;
	if (key == 13)
		init->cl_1 += 10;
	if (key == 1)
		init->cl_1 -= 10;
	if (key == 2)
		init->cl_2 -= 10;
	if (key == 14)
		init->cl_2 += 10;
	if (key == 49)
		ft_initialisation(init);
	ft_bzero(init->img_str, HIGHT * WIDTH);
	if (init->set == 0)
		ft_pthread_mandel(init);
	if (init->set == 1)
		ft_pthread_julia(init);
	if (init->set == 2)
		ft_pthread_nova(init);
}

void	ft_t_min_kees(int key, t_init *init)
{
	if (key == 78)
		init->zoom -= 0.2;
	if (key == 69)
		init->zoom += 0.2;
	if (key == 53)
	{
		free(init);
		exit(1);
	}
	if (key == 126)
	{
		init->mod_move = 2;
		init->move_vr = -fabsl(init->start_y - init->end_y) / 88;
	}
	if (key == 125)
	{
		init->mod_move = 2;
		init->move_vr = fabsl(init->start_y - init->end_y) / 88;
	}
}

int		t_kees(int key, t_init *init)
{
	ft_t_min_kees(key, init);
	if (key == 123)
	{
		init->mod_move = 1;
		init->move_hz = -fabsl(init->start_x - init->end_x) / 88;
	}
	if (key == 124)
	{
		init->mod_move = 1;
		init->move_hz = fabsl(init->start_x - init->end_x) / 88;
	}
	ft_t_kees(key, init);
	mlx_put_image_to_window(init->init, init->win, init->img, 0, 0);
	return (0);
}

int		mouse_press(int button, int x, int y, t_init *init)
{
	if (button == 4)
	{
		init->iteration -= 1;
		init->mouse_x = ft_map_x(init, x);
		init->mouse_y = ft_map_y(init, y);
		init->mod_mouse = 1;
		ft_apply_rv_zoom(init);
	}
	if (button == 5)
		ft_mouse_press(x, y, init);
	if (button == 2 && init->set == 1)
		init->what = (init->what == 1) ? 0 : 1;
	ft_bzero(init->img_str, HIGHT * WIDTH);
	if (init->set == 0)
		ft_pthread_mandel(init);
	if (init->set == 1)
		ft_pthread_julia(init);
	if (init->set == 2)
		ft_pthread_nova(init);
	mlx_put_image_to_window(init->init, init->win, init->img, 0, 0);
	return (0);
}
