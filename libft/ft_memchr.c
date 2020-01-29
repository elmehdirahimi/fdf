/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:38:35 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/10 15:57:41 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char *nvs;

	i = 0;
	nvs = s;
	while (i < n)
	{
		if ((unsigned char)c == nvs[i])
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (NULL);
}
