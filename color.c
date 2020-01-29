/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:22:58 by erahimi           #+#    #+#             */
/*   Updated: 2019/10/22 10:56:17 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				get_default_color(int z, t_fdf *fdf)
{
	double	percentage;

	percentage = percent(fdf->z_min, fdf->z_max, z);
	if (z < 0)
		return (0x15b1e0);
	if (percentage < 0.20)
		return (0x800080);
	if (percentage < 0.30)
		return (0x0000FF);
	if (percentage < 0.40)
		return (0x00FF00);
	if (percentage < 0.90)
		return (0xffa200);
	if (percentage < 0.99)
		return (0xFF0000);
	return (0x800000);
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				get_color(t_point current, t_point start,\
		t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,\
			(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF,\
			(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
