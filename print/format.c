/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:19:56 by bkuksa            #+#    #+#             */
/*   Updated: 2019/03/28 12:43:57 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_app_col(const char *str, size_t i, t_printf *bog)
{
	size_t	j;
	int		k;
	size_t	a;

	j = i;
	if (!str[i])
		bog->p = NULL;
	while (str[i] && ft_valid(str[i]) && !ft_conversion(str[i]))
		i++;
	if (ft_conversion(str[i]))
	{
		i++;
		bog->p = ft_strnew(i);
		a = i - j;
		k = -1;
		while (++k < (int)a)
			bog->p[k] = str[j++];
		bog->len = ft_strlen(bog->p);
		ft_mod_ouxid(bog);
	}
}

int		ft_bog_list(t_printf *bog)
{
	bog->s = ft_tipe_one(bog);
	bog->s = ft_apgrd(bog);
	if (bog->s == NULL)
		return (0);
	return (ft_write(bog->s, ft_strlen(bog->s), bog));
}

int		ft_valid_bog(const char *str, size_t *i)
{
	if (!str[*i])
		return (0);
	while (str[*i] && ft_valid(str[*i]) && !ft_conversion(str[*i]))
		(*i)++;
	if (ft_conversion(str[*i]) == 1)
		(*i)++;
	else
		return (5);
	return (1);
}

int		ft_write(const char *form, size_t j, t_printf *bog)
{
	if ((bog->c == 'c' || bog->c == 'C') && bog->n == 1)
		j++;
	write(1, form, j);
	if ((ft_strchr("oOuUxXfFC", bog->c) && bog->s != NULL)
	|| (bog->c == 's' && bog->z > 0) || (bog->c == 'S' && bog->z == 0)
	|| (ft_strchr("cidIDpP", bog->c) && bog->min == 0))
		ft_strdel(&(bog->s));
	return ((int)j);
}

char	*ft_prec_sc(int n, t_printf *bog)
{
	int		i;
	char	*s;

	if (n != -5 && n != -1 && !n)
	{
		if (bog->c == 'c' || bog->c == 'C')
			ft_strdel(&(bog->s));
		return (ft_strnew(1));
	}
	if (n > 0)
	{
		i = -1;
		bog->z = n;
		s = ft_strnew((size_t)n);
		n++;
		while (--n && ++i >= 0)
			s[i] = bog->s[i];
		if (bog->c == 'c' || bog->c == 'C')
			ft_strdel(&(bog->s));
		return (s);
	}
	return (bog->s);
}
