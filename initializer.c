/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:15:21 by erahimi           #+#    #+#             */
/*   Updated: 2019/10/22 11:05:28 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	mlx_initializing_a(t_fdf *fdf)
{
	fdf->offset = 700 / fdf->width;
	fdf->zoom = 1;
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, fdf->argv);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, 1000, 1000);
	fdf->data = (int *)mlx_get_data_addr(fdf->img_ptr, &(fdf->bpp),\
			&(fdf->line), &(fdf->endian));
	fdf->x_offset = 500 - (fdf->width / 2) * fdf->offset;
	fdf->y_offset = 500 - (fdf->heigth / 2) * fdf->offset;
	fdf->z_zoom = 1;
	fdf->alpha = 0;
	fdf->gamma = 0;
	fdf->beta = 0;
}

void		mlx_initializing(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	mlx_initializing_a(fdf);
	fdf->all_points = (t_point **)malloc(fdf->heigth * sizeof(t_point*));
	while (i < fdf->heigth)
	{
		fdf->all_points[i] = (t_point *)malloc(fdf->width * sizeof(t_point));
		while (j < fdf->width)
		{
			fdf->all_points[i][j].x = j * fdf->offset\
				- ((fdf->width / 2) * fdf->offset);
			fdf->all_points[i][j].y = i * fdf->offset\
				- ((fdf->heigth / 2) * fdf->offset);
			fdf->all_points[i][j].color =\
				get_default_color(fdf->z_table[i][j], fdf);
			j++;
		}
		j = 0;
		i++;
	}
}
