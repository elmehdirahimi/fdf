/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:18:19 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/19 22:55:02 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbmot(const char *s, char x)
{
	int nb;

	nb = 0;
	while (*s)
	{
		if (*s != x && (*(s + 1) == x || !(*(s + 1))))
			nb++;
		s++;
	}
	return (nb);
}

static int	*tab_size(const char *s, char x)
{
	int *tab;
	int nb;
	int i;

	i = 0;
	nb = nbmot(s, x);
	if (!(tab = (int *)malloc(sizeof(int) * nb)))
		return (NULL);
	while (nb)
	{
		tab[nb - 1] = 0;
		nb--;
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

char		**ft_strsplit(char const *s, char x)
{
	char	**fin_tab;
	int		*tab;
	int		nb;
	int		i;

	if (s == NULL)
		return (NULL);
	tab = tab_size(s, x);
	nb = nbmot(s, x);
	i = 0;
	if (!(fin_tab = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	while (i < nb)
	{
		if (!(fin_tab[i] = (char *)malloc(sizeof(char) * tab[i])))
			return (NULL);
		while (*s == x)
			s++;
		fin_tab[i] = ft_strncpy(fin_tab[i], s, tab[i]);
		fin_tab[i][tab[i]] = '\0';
		s = s + tab[i++];
	}
	fin_tab[i] = 0;
	free(tab);
	return (fin_tab);
}
