/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:25:04 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/10 19:36:03 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *temp;

	if (!(temp = (char *)malloc(sizeof(char) * (1 + size))))
		return (NULL);
	ft_bzero(temp, size);
	temp[size] = '\0';
	return (temp);
}
