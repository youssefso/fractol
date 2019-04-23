/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:51:55 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/03/17 20:43:52 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
# include "./libft/includes/libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# define WIDTH 700
# define HIGHT 500
# define ABS(X) ((X < 0) ? -X : X)

typedef struct	s_init
{
	void			*init;
	void			*img;
	void			*win;
	unsigned char	*img_str;
	long double		zoom;
	long double		mouse_x;
	long double		mouse_y;
	int				iteration;
	long double		move_hz;
	long double		move_vr;
	int				cl_0;
	int				cl_1;
	int				cl_2;
	int				mod_mouse;
	long double		start_x;
	long double		start_y;
	long double		end_x;
	long double		end_y;
	double			julia_c_y;
	double			julia_c_x;
	long double		what;
	int				set;
	int				mod_move;
}				t_init;

typedef struct	s_variables
{
	int			xx;
	int			yy;
	int			n;
	long double	x;
	long double	y;
}				t_variables;

typedef struct	s_complex
{
	long double x;
	long double y;
	long double tmp;
	long double z_x;
	long double z_y;
}				t_complex;
void			ft_initialisation(t_init *init);
void			ft_pthread_mandel(t_init *init);
void			ft_pthread_nova(t_init *init);
void			ft_pthread_julia(t_init *init);
void			*ft_nova_set_0(void *inits);
void			*ft_nova_set_3(void *inits);
void			*ft_nova_set_2(void *inits);
void			*ft_nova_set_1(void *inits);
void			*ft_mandelbrot_set_0(void *inits);
void			*ft_mandelbrot_set_3(void *inits);
void			*ft_mandelbrot_set_2(void *inits);
void			*ft_mandelbrot_set_1(void *inits);
void			*ft_julia_set_0(void *inits);
void			ft_apply_zoom(t_init *init);
void			ft_apply_rv_zoom(t_init *init);
void			*ft_julia_set_3(void *inits);
void			*ft_julia_set_2(void *inits);
void			*ft_julia_set_1(void *inits);
int				mouse_press(int button, int x, int y, t_init *init);
int				t_kees(int key, t_init *init);
long double		ft_map_y(t_init *init, int y);
long double		ft_map_x(t_init *init, int x);
int				ft_mandelbrot_itiration(t_complex c, t_init *init);
void			ft_mlx_o_event(t_init *init);
void			ft_light_pixel(t_init *v, int x, int y, int n);
void			ft_initialisation(t_init *init);
long double		ft_map_y(t_init *init, int yx);
long double		ft_map_x(t_init *init, int xx);
void			ft_mouse_press(int x, int y, t_init *init);
long double		ft_rv_zoom(long double start, long double end, long double zom);
long double		ft_zoom(long double start, long double end, long double zom);
int				mouse_move(int x, int y, t_init *init);
#endif
