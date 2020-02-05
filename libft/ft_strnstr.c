/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:56:37 by bkuksa            #+#    #+#             */
/*   Updated: 2018/11/05 19:13:44 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	const char	*a;
	const char	*b;
	int			i;

	while (*s1++ && len-- > 0)
	{
		a = s2;
		i = len;
		b = s1 - 1;
		while (*b && *a && *b++ == *a && i-- >= 0)
			++a;
		if (!*a)
			return ((char*)(s1 - 1));
	}
	return (NULL);
}
