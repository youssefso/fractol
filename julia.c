/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 13:24:10 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/03/17 15:33:48 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		ft_julia_itiration(t_complex c, t_init *init)
{
	int n;

	n = 0;
	while (n < init->iteration)
	{
		c.tmp = (c.z_x * c.z_x - c.z_y * c.z_y) + init->julia_c_x;
		c.z_y = 2 * c.z_x * c.z_y + init->julia_c_y;
		c.z_x = c.tmp;
		if (c.z_x * c.z_x + c.z_y * c.z_y > 4)
			break ;
		n++;
	}
	return (n);
}

void	*ft_julia_set_0(void *inits)
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
			c.z_y = v.y;
			c.z_x = v.x;
			v.n = ft_julia_itiration(c, init);
			ft_light_pixel(init, v.xx, v.yy, v.n);
			v.xx++;
		}
		v.yy++;
	}
	pthread_exit(0);
}

void	*ft_julia_set_1(void *inits)
{
	t_init		*init;
	t_complex	c;
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
			c.z_y = v.y;
			c.z_x = v.x;
			v.n = ft_julia_itiration(c, init);
			ft_light_pixel(init, v.xx, v.yy, v.n);
			v.xx++;
		}
		v.yy++;
	}
	pthread_exit(0);
}

void	*ft_julia_set_2(void *inits)
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
			c.z_y = v.y;
			c.z_x = v.x;
			v.n = ft_julia_itiration(c, init);
			ft_light_pixel(init, v.xx, v.yy, v.n);
			v.xx++;
		}
		v.yy++;
	}
	pthread_exit(0);
}

void	*ft_julia_set_3(void *inits)
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
			c.z_y = v.y;
			c.z_x = v.x;
			v.n = ft_julia_itiration(c, init);
			ft_light_pixel(init, v.xx, v.yy, v.n);
			v.xx++;
		}
		v.yy++;
	}
	pthread_exit(0);
}
