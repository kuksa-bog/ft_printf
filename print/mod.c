/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:19:08 by bkuksa            #+#    #+#             */
/*   Updated: 2019/03/28 12:46:29 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_mod_ouxid(t_printf *bog)
{
	int		i;

	i = 0;
	while (bog->p[i] && bog->p[i] != 'h' && bog->p[i] != 'l')
		i++;
	if (bog->p[i] == 'l' || bog->p[i] == 'h')
	{
		if (bog->p[i] && bog->p[i] == 'l' && bog->p[i + 1] == 'l')
			bog->ll = 1;
		if (bog->p[i] && bog->p[i] == 'l' && bog->p[i + 1] != 'l')
			bog->l = 1;
		if (bog->p[i] && bog->p[i] == 'h' && bog->p[i + 1] != 'h')
			bog->h = 1;
		if (bog->p[i] && bog->p[i] == 'h' && bog->p[i + 1] == 'h')
			bog->hh = 1;
	}
}

uintmax_t	ft_arg_oux(t_printf *bog)
{
	if (bog->l || bog->ll || bog->h || bog->hh)
	{
		if (bog->hh == 1 && ft_strchr("oOuUxX", bog->c))
			bog->k = (unsigned char)va_arg(bog->arg, unsigned int);
		if (bog->h == 1 && ft_strchr("oOuUxX", bog->c))
			bog->k = (unsigned short)va_arg(bog->arg, unsigned int);
		if (bog->l == 1 && ft_strchr("oOuUxX", bog->c))
			bog->k = va_arg(bog->arg, unsigned long);
		if (bog->ll == 1 && ft_strchr("oOuUxX", bog->c))
			bog->k = va_arg(bog->arg, unsigned long long);
		return (1);
	}
	else
		return (0);
}

intmax_t	ft_arg_id(t_printf *bog)
{
	if (bog->l || bog->ll || bog->h || bog->hh)
	{
		if (bog->hh == 1 && ft_strchr("iIdD", bog->c))
			bog->v = (signed char)va_arg(bog->arg, int);
		if (bog->h == 1 && ft_strchr("iIdD", bog->c))
			bog->v = (signed short)va_arg(bog->arg, int);
		if (bog->l == 1 && ft_strchr("iIdD", bog->c))
			bog->v = va_arg(bog->arg, long);
		if (bog->ll == 1 && ft_strchr("iIdD", bog->c))
			bog->v = va_arg(bog->arg, long long);
		return (1);
	}
	else
		return (0);
}

char		*ft_itoa_long(intmax_t n)
{
	char		*a;
	int			i;
	intmax_t	p;

	i = 1;
	if (n < 0)
		++i;
	p = -n;
	if (n > 0)
		p = n;
	while (p / 10 > 0 && ++i > 0)
		p = p / 10;
	if (n == LONG_MIN)
		return ("-9223372036854775808");
	a = ft_strnew((size_t)i);
	if (a == NULL)
		return (NULL);
	p = n;
	if (p < 0 && (p = -p) > 0)
		*a = '-';
	while ((i > 0 && n >= 0) | (i > 1 && n < 0)
			&& (a[--i] = (char)(p % 10 + 48)) >= 0)
		p = p / 10;
	return (a);
}

void		ft_del_bog_s(t_printf *bog, char *str)
{
	if ((ft_strchr("oOuUxXfFCc", bog->c) && bog->s != NULL)
		|| (bog->c == 's' && bog->z > 0) || (bog->c == 'S' && bog->z == 0)
		|| (ft_strchr("idIDpP", bog->c) && bog->min == 0))
		ft_strdel(&(bog->s));
	bog->s = str;
}
