/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 20:37:23 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/04/17 17:03:59 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

long double	ft_zoom(long double start, long double end, long double zom)
{
	return (start + ((end - start) * zom));
}

void		ft_mouse_press(int x, int y, t_init *init)
{
	init->iteration += 1;
	init->mouse_x = ft_map_x(init, x);
	init->mouse_y = ft_map_y(init, y);
	init->mod_mouse = 1;
	ft_apply_zoom(init);
}
