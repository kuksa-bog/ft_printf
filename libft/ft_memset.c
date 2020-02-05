/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:06:57 by bkuksa            #+#    #+#             */
/*   Updated: 2018/11/01 15:36:43 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	if (len == 0)
		return (b);
	s = (unsigned char*)b;
	while (len--)
	{
		*s = (unsigned char)c;
		if (len)
			s++;
	}
	return (b);
}
