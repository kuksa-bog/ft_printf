/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:39:11 by bkuksa            #+#    #+#             */
/*   Updated: 2019/03/28 12:47:19 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_mod_float(t_printf *bog)
{
	int		i;

	i = 0;
	while (bog->p[i] && bog->p[i] != 'l' && bog->p[i] != 'L')
		i++;
	if (bog->p[i] == 'l')
		return (va_arg(bog->arg, double));
	if (bog->p[i] == 'L')
		return (va_arg(bog->arg, long double));
	return (0.0);
}

void		ft_print_f(t_printf *bog, int n)
{
	long double	i;

	ft_print_str(bog, n);
	ft_unicod_s(bog);
	if (bog->c == 'f' || bog->c == 'F')
	{
		i = ft_mod_float(bog);
		if (i == 0.0)
			i = va_arg(bog->arg, double);
		if (n == -1)
			n = 6;
		if (!n)
			n = 0;
		bog->s = ft_itoa_long((intmax_t)i);
		bog->prec = n;
		if (n > -1000000)
			bog->s = ft_itoaf(i, n, bog, 0);
	}
}

char		*ft_itoaf_2(char *str, long double *n, int *k, int p)
{
	while ((str[0] = '.') && (*n) != 0.0 && ((*k) < p)
			&& ((*n) = (ft_pld((*n)) - (intmax_t)(ft_pld((*n)))) * 10))
		str[++(*k)] = (char)((intmax_t)(*n) % 10 + 48);
	return (str);
}

char		*ft_itoaf(long double n, int p, t_printf *bog, int k)
{
	char		*str;
	long double	z;

	z = n;
	while (bog->prec == 0 && z != 0.0
			&& (int)(z = (ft_pld(z) - (intmax_t)(ft_pld(z))) * 10) > 4)
		p = ((int)((ft_pld(z) - (intmax_t)(ft_pld(z))) * 10) <= 4) ? p : ++p;
	p = (p == 0) ? ++p : p;
	str = ft_strnew((size_t)(p) + 1);
	str = ft_itoaf_2(str, &n, &k, p);
	if (((int)(n = (ft_pld(n) - (intmax_t)(ft_pld(n))) * 10) > 4 && k <= p)
	|| bog->prec == 0)
	{
		while (bog->prec != 0 && str[k] == '9' && (str[k] = '0'))
			--k;
		if (bog->prec != 0 && str[k] != '9')
			str[k] = (char)((str[k] != '.') ? (str[k] - 47 + 48) : (str[k]));
		if (str[k] == '.' || bog->prec == 0)
			return (ft_float_god(bog->s, str, bog->prec));
	}
	while (++k <= p)
		str[k] = (char)((k == p + 1) ? '\0' : '0');
	bog->s = ft_strjoin_fix(bog->s, str, 3);
	return (bog->s);
}

char		*ft_float_god(char *s1, char *s2, int p)
{
	int		i;

	i = (int)ft_strlen(s1);
	if (((p != 0 && s2[1] == '0')
	|| (p == 0 && s2[1] >= '5' && s2[1] <= '9')) && s1[--i])
	{
		s1[i] = (char)(s1[i] == '9' ? '0' : s1[i] - 47 + 48);
		while (s1[i] == '0' && --i >= 0)
			s1[i] = (char)(s1[i] == '9' ? '0' : s1[i] - 47 + 48);
		if (i < 0 && s1[i + 1] == '0')
			s1 = ft_strjoin_fix("1", s1, 1);
	}
	if (p != 0 && s2[1] == '0')
		s1 = ft_strjoin_fix(s1, s2, 3);
	else
		ft_strdel(&s2);
	return (s1);
}
