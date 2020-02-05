/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 12:09:57 by bkuksa            #+#    #+#             */
/*   Updated: 2018/11/05 19:08:17 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;
	char	*b;
	int		i;

	i = -1;
	a = (char*)dst;
	b = (char*)src;
	if (b < a)
		while ((int)(--len) >= 0)
			*(a + len) = *(b + len);
	else
		while (++i < (int)len)
			a[i] = b[i];
	return (dst);
}
