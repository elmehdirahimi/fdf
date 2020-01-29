/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:04:29 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/19 22:35:05 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	fin;
	char	*temp;

	if (s == NULL)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	fin = ft_strlen(s);
	while (fin && (s[fin - 1] == ' '
				|| s[fin - 1] == '\t' || s[fin - 1] == '\n'))
		fin--;
	if (!(temp = ft_strnew(fin)))
		return (NULL);
	temp = ft_strncpy(temp, s, fin);
	return (temp);
}
