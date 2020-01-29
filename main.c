/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:30:28 by erahimi           #+#    #+#             */
/*   Updated: 2019/10/22 19:13:34 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdf *fdf;

	fdf = (t_fdf*)malloc(sizeof(t_fdf));
	if (argc != 2)
		ft_putendl("Usage: ./fdf file");
	else
	{
		fdf->argv = argv[1];
		fdf->z_max = -2147483648;
		fdf->z_min = 2147483647;
		if (z_table_maker(fdf) == -1)
		{
			ft_putendl("error reading");
			return (0);
		}
		mlx_initializing(fdf);
		draw(fdf);
		setup_controls(fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	return (0);
}
