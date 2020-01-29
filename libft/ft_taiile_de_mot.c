/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taiile_de_mot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 22:28:23 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/20 22:54:54 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_taiile_de_mot(const char *s, char x)
{
	int *tab;
	int nbr;
	int i;

	i = 0;
	nbr = ft_nombre_de_mot(s, x);
	if (!(tab = (int *)malloc(sizeof(int) * nbr)))
		return (NULL);
	while (nbr)
	{
		tab[nbr - 1] = 0;
		nbr--;
	}
	while (*s)
	{
		if (*s != x)
			tab[i] = tab[i] + 1;
		if (*s != x && (*(s + 1) == x || !(*(s + 1))))
			i++;
		s++;
	}
	return (tab);
}
