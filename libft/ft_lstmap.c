/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:27:57 by bkuksa            #+#    #+#             */
/*   Updated: 2018/11/08 17:50:51 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*l;
	t_list	*b;
	t_list	*n;

	if (lst == NULL)
		return (NULL);
	n = ft_lstnew(f(lst)->content, f(lst)->content_size);
	if (n == NULL)
		return (NULL);
	b = n;
	l = lst;
	while (l->next != NULL)
	{
		l = l->next;
		n->next = ft_lstnew(f(l)->content, f(l)->content_size);
		n = n->next;
	}
	return (b);
}
