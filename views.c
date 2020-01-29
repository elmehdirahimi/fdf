/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:37:58 by erahimi           #+#    #+#             */
/*   Updated: 2019/10/22 10:56:41 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

t_point		project(int i, int j, t_fdf *fdf)
{
	t_point new;
	int		z;
	int		previous_x;
	int		previous_y;

	z = fdf->z_table[i][j] * fdf->z_zoom;
	new.color = fdf->all_points[i][j].color;
	new.y = fdf->all_points[i][j].y * cos(fdf->alpha) + z * sin(fdf->alpha);
	z = -fdf->all_points[i][j].y * sin(fdf->alpha) + z * cos(fdf->alpha);
	new.x = fdf->all_points[i][j].x * cos(fdf->beta) + z * sin(fdf->beta);
	z = -new.y * sin(fdf->beta) + z * cos(fdf->beta);
	previous_x = new.x;
	previous_y = new.y;
	new.x = previous_x * cos(fdf->gamma) - previous_y * sin(fdf->gamma);
	new.y = previous_x * sin(fdf->gamma) + previous_y * cos(fdf->gamma);
	new.x = new.x * fdf->zoom + (fdf->width / 2) * fdf->offset + fdf->x_offset;
	new.y = new.y * fdf->zoom + (fdf->heigth / 2) * fdf->offset + fdf->y_offset;
	return (new);
}
