/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:57:08 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/19 22:11:01 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nv_maillon;

	if (!(nv_maillon = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	nv_maillon->next = NULL;
	if (content == NULL)
	{
		nv_maillon->content = NULL;
		nv_maillon->content_size = 0;
	}
	else
	{
		if (!(nv_maillon->content = malloc(content_size)))
		{
			free(nv_maillon);
			return (NULL);
		}
		ft_memcpy(nv_maillon->content, content, content_size);
		nv_maillon->content_size = content_size;
	}
	return (nv_maillon);
}
