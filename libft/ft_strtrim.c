/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:56:42 by bkuksa            #+#    #+#             */
/*   Updated: 2018/11/02 15:05:34 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		l;
	char	*a;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
		++i;
	j = i;
	while (s[j] != '\0')
		++j;
	while (j > i && (s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n'))
		--j;
	l = j - i;
	a = (char*)malloc(sizeof(*a) * (l + 1));
	if (a == NULL)
		return (NULL);
	j = 0;
	while (j < l)
		a[j++] = s[i++];
	a[l] = '\0';
	return (a);
}
