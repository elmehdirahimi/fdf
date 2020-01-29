/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 11:47:35 by erahimi           #+#    #+#             */
/*   Updated: 2019/10/22 11:04:43 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		z_table_free(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->heigth)
	{
		free(fdf->z_table[i]);
		i++;
	}
	free(fdf->z_table);
}

void		splited_free(char ***splited)
{
	int i;

	i = 0;
	while ((*splited)[i])
	{
		free((*splited)[i]);
		i++;
	}
	free(*splited);
}

static void	free_all_points(t_fdf *fdf)
{
	int i;

	i = fdf->heigth - 1;
	while (i >= 0)
	{
		free(fdf->all_points[i]);
		i--;
	}
	free(fdf->all_points);
}

void		fdf_free(t_fdf *fdf)
{
	free_all_points(fdf);
	z_table_free(fdf);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	fdf->img_ptr = NULL;
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf->win_ptr = NULL;
	fdf->mlx_ptr = NULL;
}
