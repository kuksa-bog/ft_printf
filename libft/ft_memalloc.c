/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:15:36 by bkuksa            #+#    #+#             */
/*   Updated: 2018/11/12 12:49:12 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	s = (void*)malloc(sizeof(void*) * size);
	if (s == NULL)
	{
		return (NULL);
	}
	ft_bzero(s, size);
	return (s);
}
