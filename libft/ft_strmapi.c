/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:13:30 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/18 15:48:25 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*temp;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(temp = ft_strnew(ft_strlen(s))))
	{
		return (NULL);
	}
	while (s[i])
	{
		temp[i] = (*f)(i, s[i]);
		i++;
	}
	return (temp);
}
