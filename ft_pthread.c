/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 13:28:32 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/03/17 15:33:27 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_pthread_mandel(t_init *init)
{
	int				i;
	pthread_t		t_ip[4];
	pthread_attr_t	attr;

	pthread_attr_init(&attr);
	pthread_create(&t_ip[0], &attr, ft_mandelbrot_set_0, init);
	pthread_create(&t_ip[1], &attr, ft_mandelbrot_set_1, init);
	pthread_create(&t_ip[2], &attr, ft_mandelbrot_set_2, init);
	pthread_create(&t_ip[3], &attr, ft_mandelbrot_set_3, init);
	i = -1;
	init->set = 0;
	while (++i < 4)
		pthread_join(t_ip[i], NULL);
}

void	ft_pthread_julia(t_init *init)
{
	int				i;
	pthread_t		t_id[4];
	pthread_attr_t	attr;

	pthread_attr_init(&attr);
	pthread_create(&t_id[0], &attr, ft_julia_set_0, init);
	pthread_create(&t_id[1], &attr, ft_julia_set_1, init);
	pthread_create(&t_id[2], &attr, ft_julia_set_2, init);
	pthread_create(&t_id[3], &attr, ft_julia_set_3, init);
	i = -1;
	init->set = 1;
	while (++i < 4)
		pthread_join(t_id[i], NULL);
}

void	ft_pthread_nova(t_init *init)
{
	int				i;
	pthread_t		t_ip[4];
	pthread_attr_t	attr;

	pthread_attr_init(&attr);
	pthread_create(&t_ip[0], &attr, ft_nova_set_0, init);
	pthread_create(&t_ip[1], &attr, ft_nova_set_1, init);
	pthread_create(&t_ip[2], &attr, ft_nova_set_2, init);
	pthread_create(&t_ip[3], &attr, ft_nova_set_3, init);
	i = -1;
	init->set = 2;
	while (++i < 4)
		pthread_join(t_ip[i], NULL);
}
