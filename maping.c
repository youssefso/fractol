/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 13:26:12 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/04/17 17:04:05 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void		ft_apply_zoom(t_init *init)
{
	long double	zoom;

	zoom = 1 / init->zoom;
	init->start_x = ft_zoom(init->mouse_x, init->start_x, zoom);
	init->start_y = ft_zoom(init->mouse_y, init->start_y, zoom);
	init->end_x = ft_zoom(init->mouse_x, init->end_x, zoom);
	init->end_y = ft_zoom(init->mouse_y, init->end_y, zoom);
}

long double	ft_rv_zoom(long double start, long double end, long double zom)
{
	return (start + ((end - start) / zom));
}

void		ft_apply_rv_zoom(t_init *init)
{
	long double	zoom;

	zoom = 1 / init->zoom;
	init->start_x = ft_rv_zoom(init->mouse_x, init->start_x, zoom);
	init->start_y = ft_rv_zoom(init->mouse_y, init->start_y, zoom);
	init->end_x = ft_rv_zoom(init->mouse_x, init->end_x, zoom);
	init->end_y = ft_rv_zoom(init->mouse_y, init->end_y, zoom);
}

long double	ft_map_y(t_init *init, int yx)
{
	long double y;

	if (init->mod_move == 2)
	{
		init->start_y += init->move_vr;
		init->end_y += init->move_vr;
		init->mod_move = 0;
	}
	y = (long double)yx / (HIGHT / (init->end_y - init->start_y))
		+ init->start_y;
	return (y);
}

long double	ft_map_x(t_init *init, int xx)
{
	long double x;

	if (init->mod_move == 1)
	{
		init->start_x += init->move_hz;
		init->end_x += init->move_hz;
		init->mod_move = 0;
	}
	x = (long double)xx / (WIDTH / (init->end_x - init->start_x))
		+ init->start_x;
	return (x);
}
