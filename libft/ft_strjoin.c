/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 13:46:40 by bkuksa            #+#    #+#             */
/*   Updated: 2018/11/08 18:23:22 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ct(char *s1, const char *s2)
{
	int		i;
	int		j;

	if (s2 == NULL)
		return (s1);
	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

static char		*scp(char *dest, const char *src)
{
	size_t	i;

	if (src == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t	sl(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*a;

	if (!s1 && !s2)
		return (NULL);
	i = sl(s1) + sl(s2);
	a = (char*)malloc(sizeof(*a) * (i + 1));
	if (a == NULL)
		return (NULL);
	scp(a, s1);
	ct(a, s2);
	return (a);
}
