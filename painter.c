/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:27:00 by erahimi           #+#    #+#             */
/*   Updated: 2019/10/22 11:08:16 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (x < 1000 && x >= 0 && y >= 0 && y < 1000)
		fdf->data[x + y * 1000] = color;
}

static	void	draw_line(t_point a, t_point b, t_fdf *fdf)
{
	fdf->delta.x = b.x > a.x ? (b.x - a.x) : (a.x - b.x);
	fdf->delta.y = b.y > a.y ? (b.y - a.y) : (a.y - b.y);
	fdf->sign.x = a.x < b.x ? 1 : -1;
	fdf->sign.y = a.y < b.y ? 1 : -1;
	fdf->e_a = 0;
	fdf->e_b = 0;
	fdf->cur = a;
	while (fdf->cur.x != b.x || fdf->cur.y != b.y)
	{
		put_pixel(fdf, fdf->cur.x, fdf->cur.y,\
				get_color(fdf->cur, a, b, fdf->delta));
		fdf->e_a += fdf->delta.y;
		fdf->e_b += fdf->delta.x;
		if (2 * fdf->e_a >= fdf->delta.x)
		{
			fdf->e_a -= fdf->delta.x;
			fdf->cur.y += fdf->sign.y;
		}
		if (2 * fdf->e_b >= fdf->delta.y)
		{
			fdf->e_b -= fdf->delta.y;
			fdf->cur.x += fdf->sign.x;
		}
	}
}

static	void	ft_background(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			put_pixel(fdf, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
	if (fdf->width == 1 && fdf->heigth == 1)
		put_pixel(fdf, 500, 500, 0x000000);
}

void			draw(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	ft_background(fdf);
	while (i < fdf->heigth)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (j != fdf->width - 1)
				draw_line(project(i, j, fdf), project(i, j + 1, fdf), fdf);
			if (i != fdf->heigth - 1)
				draw_line(project(i, j, fdf), project(i + 1, j, fdf), fdf);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 950, 0x000080\
			, "paralelle(p) iso(i) deplacer(8-4-2-6)  zoom(+ -)\
			rotatation(left-right-up-down-q-w)  atitude(z-x)");
}
