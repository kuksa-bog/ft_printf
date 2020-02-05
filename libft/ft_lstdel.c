/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:48:02 by bkuksa            #+#    #+#             */
/*   Updated: 2018/11/06 12:48:43 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*lnext;

	lst = *alst;
	while (lst)
	{
		lnext = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = lnext;
	}
	*alst = NULL;
}
