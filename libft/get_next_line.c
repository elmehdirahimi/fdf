/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:10:20 by erahimi           #+#    #+#             */
/*   Updated: 2019/10/06 13:06:22 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_recover(char *str, char **line)
{
	int		i;
	char	*rst;

	i = 0;
	while ((str[i] != '\0' && (str[i] != '\n')))
		i++;
	*line = ft_strsub(str, 0, i);
	if (str[i] == '\n')
		rst = ft_strdup((str + i + 1));
	else
		rst = ft_strnew(0);
	return (rst);
}

int			get_next_line(const int fd, char **line)
{
	char		*temp;
	static char *str[4864];
	size_t		nbread;
	char		buff[BUFF_SIZE + 1];

	if ((fd > 4864) || (fd < 0) || (read(fd, buff, 0) < 0))
		return (-1);
	while ((nbread = read(fd, buff, BUFF_SIZE)))
	{
		if (!str[fd])
			str[fd] = ft_strnew(0);
		buff[nbread] = '\0';
		temp = str[fd];
		str[fd] = ft_strjoin(str[fd], buff);
		free(temp);
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if ((ft_strlen(str[fd]) == 0) && (nbread == 0))
		return (0);
	temp = ft_recover(str[fd], line);
	free(str[fd]);
	str[fd] = temp;
	return (1);
}
