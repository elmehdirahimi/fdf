/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:31:10 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/10 12:59:02 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	char		*a;
	const char	*b;

	i = 0;
	a = (char *)dest;
	b = (const char *)src;
	while (i < (int)n)
	{
		a[i] = b[i];
		i++;
	}
	return (dest);
}
