/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:28:24 by erahimi           #+#    #+#             */
/*   Updated: 2019/10/06 12:12:27 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>

typedef struct		s_point
{
	int x;
	int y;
	int color;
}					t_point;

typedef struct		s_fdf
{
	t_point			**all_points;
	int				x_offset;
	int				y_offset;
	char			*argv;
	int				**z_table;
	int				z_min;
	int				z_max;
	int				fd;
	int				width;
	int				heigth;
	int				offset;
	void			*mlx_ptr;
	void			*win_ptr;
	int				*data;
	void			*img_ptr;
	int				bpp;
	int				endian;
	int				line;
	double			alpha;
	double			beta;
	double			gamma;
	int				position_x;
	int				position_y;
	float			z_zoom;
	float			zoom;
	t_point			delta;
	t_point			sign;
	t_point			cur;
	int				e_a;
	int				e_b;
}					t_fdf;

int					get_default_color(int z, t_fdf *fdf);
double				percent(int start, int end, int current);
int					z_table_maker(t_fdf *fdf);
void				mlx_initializing(t_fdf *fdf);
int					get_color(t_point current, t_point start,\
		t_point end, t_point delta);
t_point				project(int i, int j, t_fdf *fdf);
void				draw(t_fdf *fdf);
void				setup_controls(t_fdf *fdf);
void				z_table_free(t_fdf *fdf);
void				splited_free(char ***splited);
void				fdf_free(t_fdf *fdf);

#endif
