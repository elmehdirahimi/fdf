/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:09:48 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/10 16:45:38 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	nvc;
	unsigned char	*nvdst;
	unsigned char	*nvsrc;

	i = 0;
	nvc = (unsigned char)c;
	nvsrc = (unsigned char *)src;
	nvdst = (unsigned char *)dst;
	while (i < n)
	{
		nvdst[i] = nvsrc[i];
		i++;
		if (nvdst[i - 1] == nvc)
			return (nvdst + i);
	}
	return (NULL);
}
