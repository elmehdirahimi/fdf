/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:17:05 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/18 15:12:24 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *temp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	temp = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (temp == NULL)
		return (NULL);
	ft_strcpy(temp, s1);
	ft_strcat(temp, s2);
	return (temp);
}
