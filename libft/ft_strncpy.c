/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:26:24 by bkuksa            #+#    #+#             */
/*   Updated: 2018/11/05 19:13:18 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*a;
	const char	*s;
	int			k;

	k = len;
	if (!dst && !src)
		return (NULL);
	if (ft_strlen(src) < (size_t)k)
		k = -1;
	a = dst;
	s = src;
	while (len-- > 0 && *s)
		*a++ = *s++;
	++len;
	while (k < 0 && len-- > 0)
		*a++ = '\0';
	return (dst);
}
