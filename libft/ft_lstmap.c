/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 21:29:08 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/20 22:53:24 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*frais;

	if (lst != NULL)
	{
		frais = (t_list *)malloc(sizeof(t_list));
		frais = f(lst);
		frais->next = ft_lstmap(lst->next, f);
		return (frais);
	}
	return (NULL);
}
