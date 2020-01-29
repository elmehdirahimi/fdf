/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:02:52 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/18 15:11:07 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(temp = ft_strnew(len)))
		return (0);
	while (i < len)
	{
		temp[i] = s[start + i];
		i++;
	}
	return (temp);
}
