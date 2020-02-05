/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:02:15 by bkuksa            #+#    #+#             */
/*   Updated: 2018/11/01 14:26:15 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*a;
	unsigned const char	*b;

	if (s1 == s2 || n == 0)
		return (0);
	a = (unsigned const char*)s1;
	b = (unsigned const char*)s2;
	while (n-- > 0)
	{
		if (*a != *b)
			return (*a - *b);
		if (n)
		{
			a++;
			b++;
		}
	}
	return (0);
}
