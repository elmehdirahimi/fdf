/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:16:34 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/18 14:34:09 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char*)b;
	while (i < (int)len)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return ((void*)dest);
}
