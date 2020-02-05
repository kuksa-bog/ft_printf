/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:26:13 by bkuksa            #+#    #+#             */
/*   Updated: 2019/03/28 12:45:17 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_bit_size(unsigned i)
{
	size_t			k;

	k = 0;
	while (i > 0 && ++k)
		i = i >> 1;
	if (k <= 7 || (k > 7 && k <= 11))
		return ((k <= 7) ? 1 : 2);
	else if (k <= 16 || (k > 16 && k <= 21))
		return ((k <= 16) ? 3 : 4);
	else
		return (0);
}

char	*ft_print_wchar(unsigned int z, char *str, size_t j)
{
	if (j == 1)
		str[0] = (char)z;
	else if (j == 2)
	{
		str[0] = (char)(((unsigned)MASK1 >> 8) | (((z >> 6) << 27) >> 27));
		str[1] = (char)((((unsigned)MASK1 << 24) >> 24) | ((z << 26) >> 26));
	}
	else if (j == 3)
	{
		str[0] = (char)(((unsigned)MASK2 >> 16) | (((z >> 12) << 28) >> 28));
		str[1] = (char)
				((((unsigned)MASK2 << 16) >> 24) | (((z >> 6) << 26) >> 26));
		str[2] = (char)((((unsigned)MASK2 << 24) >> 24) | ((z << 26) >> 26));
	}
	else if (j == 4)
	{
		str[0] = (char)(((MASK3 >> 24) | (((z >> 18) << 29) >> 29)));
		str[1] = (char)
				((((MASK3 >> 16) << 24) >> 24) | (((z >> 12) << 26) >> 26));
		str[2] = (char)
				((((MASK3 >> 8) << 24) >> 24) | (((z >> 6) << 26) >> 26));
		str[3] = (char)(((MASK3 << 24) >> 24) | ((z << 26) >> 26));
	}
	str[j] = '\0';
	return (str);
}

void	ft_unicod_s(t_printf *bog)
{
	wchar_t		*s;
	char		*str;
	int			i;

	if (bog->c == 'C' || (bog->c == 'c' && bog->l == 1))
		bog->s = ft_unicod_c(bog, 0, NULL);
	if (bog->c == 'S' || (bog->c == 's' && bog->l == 1))
	{
		s = va_arg(bog->arg, wchar_t*);
		i = -1;
		if (s == NULL && (bog->z = 1))
			bog->s = "(null)";
		while (s != NULL && s[++i])
		{
			str = ft_unicod_c(bog, s[i], NULL);
			bog->s = ft_strjoin_fix(bog->s, str, 3);
		}
	}
}

char	*ft_unicod_c(t_printf *bog, wchar_t z, char *str)
{
	size_t		j;

	while (bog->p[bog->len - 1] == 'C' || bog->c == 'c'
	|| ((bog->c == 'S' || bog->c == 's') && z != 0))
	{
		if (z == 0)
			z = va_arg(bog->arg, wchar_t);
		if (z == 0 && (bog->n = 1))
			return (ft_strnew(1));
		j = ft_bit_size((unsigned int)z);
		str = ft_strnew(j);
		str = ft_print_wchar((unsigned int)z, str, j);
		return (str);
	}
	return (NULL);
}

char	*ft_strjoin_fix(char *s1, char *s2, int n)
{
	char	*s3;

	s3 = NULL;
	if (n == 1)
	{
		s3 = ft_strjoin(s1, s2);
		ft_strdel(&s2);
	}
	if (n == 2)
	{
		s3 = ft_strjoin(s1, s2);
		ft_strdel(&s1);
	}
	if (n == 3)
	{
		s3 = ft_strjoin(s1, s2);
		ft_strdel(&s2);
		ft_strdel(&s1);
	}
	return (s3);
}
