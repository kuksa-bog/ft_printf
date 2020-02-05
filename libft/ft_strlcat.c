/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:32:16 by bkuksa            #+#    #+#             */
/*   Updated: 2018/11/05 19:11:08 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	int i;
	int k;
	int l;

	i = ft_strlen(dst);
	k = 0;
	l = 0;
	if (i < (int)n)
		l = i;
	else
		l = (int)n;
	while (src[k] != '\0' && i < (int)n - 1)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (l + ft_strlen(src));
}
