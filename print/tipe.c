/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:21:19 by bkuksa            #+#    #+#             */
/*   Updated: 2019/03/20 11:32:16 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_tipe_one(t_printf *bog)
{
	bog->c = bog->p[ft_strlen(bog->p) - 1];
	if ((bog->s = ft_print_int(bog, bog->c)) != NULL)
		return (bog->s);
	if (bog->c == 's' || bog->c == 'f' || bog->c == 'C' || bog->c == 'S')
		return (NULL);
	if ((bog->s = ft_print_x(bog, bog->c)) != NULL)
		return (bog->s);
	if ((bog->s = ft_print_uo(bog, bog->c)) != NULL)
		return (bog->s);
	if ((bog->s = ft_print_p(bog)) != NULL)
		return (bog->s);
	if ((bog->s = ft_char(bog)) != NULL)
		return (bog->s);
	if (bog->c == '%' && (bog->s = "%") != NULL)
		return (bog->s);
	return (NULL);
}

void		ft_print_str(t_printf *bog, int n)
{
	if (bog->c == 's' && bog->l == 0)
	{
		bog->s = va_arg(bog->arg, char *);
		if (bog->s == NULL && (bog->s = "(null)"))
		{
			if (n == -1)
				n = -5;
		}
		if (n == -5)
			bog->z = 0;
		if (n < (int)ft_strlen(bog->s))
			bog->s = ft_prec_sc(n, bog);
	}
}

char		*ft_print_int(t_printf *bog, char c)
{
	char		*s;

	if (c == 'd' || c == 'i' || c == 'I' || c == 'D')
	{
		if ((c == 'd' || c == 'i' || c == 'I') && (ft_arg_id(bog)) == 0)
			bog->v = va_arg(bog->arg, int);
		if (c == 'D')
			bog->v = va_arg(bog->arg, long long);
		s = ft_itoa_long(bog->v);
		if (ft_strcmp(s, "-9223372036854775808") == 0)
			bog->min = 1;
		return (s);
	}
	return (NULL);
}

char		*ft_char(t_printf *bog)
{
	if (bog->c == 'c' && bog->l == 0)
	{
		bog->ch = (char)va_arg(bog->arg, int);
		bog->s = ft_strnew(1);
		bog->n = (bog->ch == 0) ? 1 : 0;
		bog->s[0] = bog->ch;
		return (bog->s);
	}
	return (NULL);
}

long double	ft_pld(long double d)
{
	return (d < 0 ? -d : d);
}
