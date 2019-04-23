/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 13:22:59 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/04/21 17:48:06 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		ft_mandelbrot_itiration(t_complex c, t_init *init)
{
	int n;

	n = 0;
	c.z_x = 0;
	c.z_y = 0;
	while (n < init->iteration)
	{
		c.tmp = (c.z_x * c.z_x - c.z_y * c.z_y) + c.x;
		c.z_y = 2 * c.z_x * c.z_y + c.y;
		c.z_x = c.tmp;
		if (c.z_x * c.z_x + c.z_y * c.z_y > 4)
			break ;
		n++;
	}
	return (n);
}

void	*ft_mandelbrot_set_0(void *inits)
{
	t_init		*init;
	t_complex	c;
	t_variables	v;

	init = (t_init *)inits;
	v.yy = 0;
	while (v.yy < HIGHT / 4)
	{
		v.y = ft_map_y(init, v.yy);
		v.xx = 0;
		while (v.xx < WIDTH)
		{
			v.x = ft_map_x(init, v.xx);
			c.y = v.y;
			c.x = v.x;
			v.n = ft_mandelbrot_itiration(c, init);
			ft_light_pixel(init, v.xx, v.yy, v.n);
			v.xx++;
		}
		v.yy++;
	}
	pthread_exit(0);
}

void	*ft_mandelbrot_set_1(void *inits)
{
	t_complex	c;
	t_init		*init;
	t_variables	v;

	init = (t_init *)inits;
	v.yy = HIGHT / 4;
	while (v.yy < HIGHT / 2)
	{
		v.y = ft_map_y(init, v.yy);
		v.xx = 0;
		while (v.xx < WIDTH)
		{
			v.x = ft_map_x(init, v.xx);
			c.y = v.y;
			c.x = v.x;
			v.n = ft_mandelbrot_itiration(c, init);
			ft_light_pixel(init, v.xx, v.yy, v.n);
			v.xx++;
		}
		v.yy++;
	}
	pthread_exit(0);
}

void	*ft_mandelbrot_set_2(void *inits)
{
	t_init		*init;
	t_complex	c;
	t_variables	v;

	init = (t_init *)inits;
	v.yy = HIGHT / 2;
	while (v.yy < HIGHT * 3 / 4)
	{
		v.y = ft_map_y(init, v.yy);
		v.xx = 0;
		while (v.xx < WIDTH)
		{
			v.x = ft_map_x(init, v.xx);
			c.y = v.y;
			c.x = v.x;
			v.n = ft_mandelbrot_itiration(c, init);
			ft_light_pixel(init, v.xx, v.yy, v.n);
			v.xx++;
		}
		v.yy++;
	}
	pthread_exit(0);
}

void	*ft_mandelbrot_set_3(void *inits)
{
	t_init		*init;
	t_complex	c;
	t_variables	v;

	init = (t_init *)inits;
	v.yy = HIGHT * 3 / 4;
	while (v.yy < HIGHT)
	{
		v.y = ft_map_y(init, v.yy);
		v.xx = 0;
		while (v.xx < WIDTH)
		{
			v.x = ft_map_x(init, v.xx);
			c.y = v.y;
			c.x = v.x;
			v.n = ft_mandelbrot_itiration(c, init);
			ft_light_pixel(init, v.xx, v.yy, v.n);
			v.xx++;
		}
		v.yy++;
	}
	pthread_exit(0);
}
