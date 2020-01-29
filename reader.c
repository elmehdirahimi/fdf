/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:07:05 by erahimi           #+#    #+#             */
/*   Updated: 2019/10/22 10:57:24 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		nb_line(t_fdf *fdf)
{
	int		i;
	char	*line;
	char	buff[1];

	line = NULL;
	if ((fdf->fd = open(fdf->argv, O_RDONLY)) < 0)
		return (-1);
	if ((fdf->fd > 4864) || (fdf->fd < 0) || (read(fdf->fd, buff, 1) <= 0))
		return (-1);
	close(fdf->fd);
	if ((fdf->fd = open(fdf->argv, O_RDONLY)) < 0)
		return (-1);
	i = 0;
	while (get_next_line(fdf->fd, &line) > 0)
	{
		if (line)
			free(line);
		i++;
	}
	close(fdf->fd);
	return (i);
}

static int		ft_strlen_new(char **splited)
{
	int i;

	i = 0;
	while (splited[i])
		i++;
	return (i);
}

static int		*splite_to_z(char **splited, int size, t_fdf *fdf)
{
	int	i;
	int	*z_line;

	if (!(z_line = (int *)malloc(size * sizeof(int) + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		z_line[i] = ft_atoi(splited[i]) * 10;
		if (fdf->z_max < z_line[i])
			fdf->z_max = z_line[i];
		if (fdf->z_min > z_line[i])
			fdf->z_min = z_line[i];
		i++;
	}
	return (z_line);
}

static int		process(char **splited, t_fdf *fdf, char **line, int i)
{
	if (!splited)
		return (-1);
	if ((fdf->width != -1) && (fdf->width > ft_strlen_new(splited)))
	{
		splited_free(&splited);
		return (-1);
	}
	if (i == 0)
		fdf->width = ft_strlen_new(splited);
	if (!(fdf->z_table[i] = splite_to_z(splited, fdf->width, fdf)))
		return (-1);
	splited_free(&splited);
	free(*line);
	return (1);
}

int				z_table_maker(t_fdf *fdf)
{
	char	*line;
	char	**splited;
	int		i;

	fdf->width = -1;
	i = 0;
	if ((fdf->heigth = nb_line(fdf)) == -1)
		return (-1);
	fdf->z_table = (int **)malloc(fdf->heigth * sizeof(int *) + 1);
	if ((fdf->fd = open(fdf->argv, O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(fdf->fd, &line) > 0)
	{
		splited = ft_strsplit(line, ' ');
		if (process(splited, fdf, &line, i) == -1)
			return (-1);
		i++;
	}
	close(fdf->fd);
	if (i == 0)
		return (-1);
	return (1);
}
