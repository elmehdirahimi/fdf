/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:49:25 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/19 20:25:41 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	divi(long n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*tab;
	size_t	siz;
	long	nb;
	int		x;

	x = 0;
	nb = n;
	siz = divi(nb);
	if (nb < 0)
		x++;
	if (!(tab = ft_strnew(siz + x)))
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		tab[0] = '-';
	}
	while (siz)
	{
		tab[siz + x - 1] = '0' + (nb % 10);
		nb = nb / 10;
		siz--;
	}
	return (tab);
}
