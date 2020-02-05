/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:48:20 by bkuksa            #+#    #+#             */
/*   Updated: 2018/11/05 18:51:56 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char *a;
	const char *b;

	if (!*s2)
		return ((char*)s1);
	while (*s1++)
	{
		a = s2;
		b = s1 - 1;
		while (*a && *b && *a == *b++)
			++a;
		if (!*a)
			return ((char*)(s1 - 1));
	}
	return (NULL);
}
