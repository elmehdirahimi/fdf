/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:31:06 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/10 13:11:18 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*sh1;
	unsigned char	*sh2;

	sh1 = (unsigned char *)s1;
	sh2 = (unsigned char *)s2;
	i = 0;
	while ((sh1[i] != '\0' || sh2[i] != '\0') && i < n)
	{
		if (sh1[i] != sh2[i])
			return (sh1[i] - sh2[i]);
		i++;
	}
	return (0);
}
