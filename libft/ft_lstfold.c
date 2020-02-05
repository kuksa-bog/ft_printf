/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:14:01 by bkuksa            #+#    #+#             */
/*   Updated: 2018/11/12 13:50:47 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfold(t_list *list, void *(*f)(const void *, const void*, size_t))
{
	void	*rezult;
	t_list	*lst;

	lst = list;
	if (lst != NULL)
	{
		rezult = lst->content;
		lst = lst->next;
		while (lst != NULL)
		{
			rezult = (*f)(rezult, lst->content, lst->content_size);
			lst = lst->next;
		}
		return (rezult);
	}
	return (NULL);
}
