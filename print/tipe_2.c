/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tipe_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:45:23 by bkuksa            #+#    #+#             */
/*   Updated: 2019/02/27 18:13:05 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_x(t_printf *bog, char c)
{
	char		*s;

	if (c == 'x')
	{
		if (ft_arg_oux(bog) == 0)
			bog->k = va_arg(bog->arg, unsigned);
		s = ft_hex(bog->k, 16, "0123456789abcdef");
		return (s);
	}
	if (c == 'X')
	{
		if (ft_arg_oux(bog) == 0)
			bog->k = va_arg(bog->arg, unsigned);
		s = ft_hex(bog->k, 16, "0123456789ABCDEF");
		return (s);
	}
	return (NULL);
}

char	*ft_print_p(t_printf *bog)
{
	char			*s;
	uintmax_t		d;

	if (bog->c == 'p' || bog->c == 'P')
	{
		d = va_arg(bog->arg, uintmax_t);
		s = ft_hex(d, 16, "0123456789abcdef");
		s = ft_strjoin_fix("0x", s, 1);
		return (s);
	}
	return (NULL);
}

char	*ft_print_uo(t_printf *bog, char c)
{
	char		*s;

	if (c == 'u' || c == 'U')
	{
		if (c == 'u' && ft_arg_oux(bog) == 0)
			bog->k = va_arg(bog->arg, unsigned);
		if (c == 'U')
			bog->k = va_arg(bog->arg, unsigned long long);
		s = ft_hex(bog->k, 10, "0123456789");
		return (s);
	}
	if (c == 'o' || c == 'O')
	{
		if (c == 'o' && ft_arg_oux(bog) == 0)
			bog->k = va_arg(bog->arg, unsigned);
		if (c == 'O')
			bog->k = va_arg(bog->arg, unsigned long long);
		s = ft_hex(bog->k, 8, "01234567");
		return (s);
	}
	return (NULL);
}

char	*ft_hex(uintmax_t d, int base, char *str)
{
	uintmax_t	i;
	size_t		len;
	char		*s;

	i = d;
	len = 1;
	while ((i /= base))
		len++;
	s = (char *)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	i = d;
	s[--len] = str[i % base];
	while ((i /= base))
		s[--len] = str[i % base];
	return (s);
}

void	ft_bog_upp(t_printf *bog)
{
	bog->n = 0;
	bog->prec = 0;
	bog->ll = 0;
	bog->l = 0;
	bog->h = 0;
	bog->hh = 0;
	bog->len = 0;
	bog->min = 0;
	bog->k = 0;
	bog->v = 0;
	bog->ch = '\0';
	bog->c = '\0';
	bog->z = 0;
	bog->p = NULL;
	bog->tup = 0;
	bog->s = NULL;
}
