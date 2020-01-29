/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:29:01 by erahimi           #+#    #+#             */
/*   Updated: 2019/10/22 11:03:59 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		rotate(int key, t_fdf *fdf)
{
	if (key == 126)
		fdf->alpha -= 0.1;
	if (key == 125)
		fdf->alpha += 0.1;
	if (key == 123)
		fdf->beta -= 0.1;
	if (key == 124)
		fdf->beta += 0.1;
	if (key == 12)
		fdf->gamma += 0.1;
	if (key == 14)
		fdf->gamma -= 0.1;
	if (key == 34)
	{
		fdf->alpha = -0.955316618;
		fdf->gamma = 0.45;
		fdf->beta = -0.615479709;
	}
	if (key == 35)
	{
		fdf->alpha = 0;
		fdf->gamma = 0;
		fdf->beta = 0;
	}
	draw(fdf);
}

static void		move(int key, t_fdf *fdf)
{
	if (key == 86)
		fdf->x_offset -= 10;
	else if (key == 88)
		fdf->x_offset += 10;
	else if (key == 91)
		fdf->y_offset -= 10;
	else
		fdf->y_offset += 10;
	draw(fdf);
}

static void		zooming(int key, t_fdf *fdf)
{
	if (key == 69)
		fdf->zoom += 0.04;
	if (key == 78)
		fdf->zoom -= 0.04;
	if (fdf->zoom < 0.01)
		fdf->zoom = 0.01;
	if (key == 6)
		fdf->z_zoom += 0.04;
	if (key == 7)
		fdf->z_zoom -= 0.04;
	if (fdf->z_zoom < 0.01)
		fdf->z_zoom = 0.01;
	draw(fdf);
}

static int		key_press(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		fdf_free(fdf);
		free(fdf);
		exit(0);
	}
	if (key == 123 || key == 124 || key == 125
			|| key == 126 || key == 12 || key == 14
			|| key == 34 || key == 35)
		rotate(key, fdf);
	if (key == 84 || key == 86 || key == 91 || key == 88)
		move(key, fdf);
	if (key == 69 || key == 78 || key == 6 || key == 7)
		zooming(key, fdf);
	return (0);
}

void			setup_controls(t_fdf *fdf)
{
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
}
