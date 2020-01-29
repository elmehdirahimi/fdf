/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:32:16 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/19 22:34:36 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t size_of_dest;
	size_t size_of_src;

	size_of_dest = ft_strlen((const char *)dest);
	size_of_src = ft_strlen((const char *)src);
	if (size_of_dest >= size)
	{
		return (size + size_of_src);
	}
	else
	{
		ft_strncat(dest, src, size - size_of_dest - 1);
		return (size_of_src + size_of_dest);
	}
}
