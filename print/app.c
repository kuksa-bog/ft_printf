/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:22:16 by bkuksa            #+#    #+#             */
/*   Updated: 2019/03/28 12:43:06 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apgrd(t_printf *bog)
{
	size_t	i;
	char	*str;
	int		n;

	n = -1;
	str = ft_strnew(11);
	i = 0;
	if (ft_strchr("123456789", bog->p[i]) != NULL
	|| ft_strchr("fsSC", bog->c) != NULL
	|| ft_flag(bog->p[i]) != 0
	|| ft_conversion(bog->c) != 0)
	{
		ft_inttup_f(bog, i, str, n);
		ft_hash_plus(bog, i);
		ft_space(bog, i);
		ft_zero(bog, i, n);
		ft_minus(bog, i);
		ft_int_s(bog, i);
	}
	return (bog->s);
}

void	ft_inttup_f(t_printf *b, size_t i, char *str, int n)
{
	while ((ft_flag(b->p[i]) != 0) || (b->p[i] >= '0' && b->p[i] <= '9'))
		i++;
	if (b->p[i] == '.')
	{
		if ((b->c == 'p' || b->c == 'P')
			&& ft_strcmp("0x0", b->s) == 0 && (b->min = 1))
		{
			ft_strdel(&(b->s));
			b->s = "0x";
		}
		while (b->p[++i] >= '0' && b->p[i] <= '9')
			str[++n] = b->p[i];
		n = (ft_atoi(str) > 0 ? ft_atoi(str) : 0);
		if (ft_strchr("iIdDuUoOxXpP", b->c) != NULL && (b->tup = 1) > 0)
		{
			n = (ft_atoi(b->s) < 0) ? n + 1 : n;
			b->s = (n > (int)ft_strlen(b->s) ? ft_write_zero(b, n, -1) : b->s);
			b->s = (n == 0 && ft_atoi(b->s) == 0 && b->ch == 0 && b->c != 'p')
					? ft_strnew(1) : b->s;
		}
		ft_print_f(b, n);
	}
	else
		ft_print_f(b, -1);
	ft_strdel(&str);
}

char	*ft_write_zero(t_printf *bog, int n, int i)
{
	int		k;
	char	*str;

	k = n - (int)ft_strlen(bog->s) + 1;
	str = ft_strnew((size_t)n);
	if ((bog->c == 'p' || bog->c == 'P')
		|| (ft_strchr(bog->p, '#') && ft_strchr("oO", bog->c)))
		k = (bog->c == 'p' || bog->c == 'P') ? k + 2 : k - 1;
	if (bog->s[0] == '-')
		str[++i] = '-';
	while (ft_strchr("pP", bog->c) == NULL && --k && ++i >= 0)
		str[i] = '0';
	n = (str[0] == '-' ? 0 : -1);
	while (bog->c != 'p' && bog->c != 'P' && bog->s[++n])
		str[++i] = bog->s[n];
	while ((bog->c == 'p' || bog->c == 'P') && ft_strcmp("0x", str) != 0)
		str[++i] = bog->s[++n];
	while (ft_strchr("pP", bog->c) != NULL && --k && ++i >= 0)
		str[i] = '0';
	while ((bog->c == 'p' || bog->c == 'P') && bog->s[++n - 1])
		str[++i] = (char)((bog->s[n]) ? bog->s[n] : '\0');
	ft_del_bog_s(bog, str);
	return (bog->s);
}

void	ft_space(t_printf *bog, size_t i)
{
	if (ft_strchr("iDdIfF", bog->c) != NULL && ft_atoi(bog->s) >= 0
	&& bog->n_spec != 1)
	{
		while (bog->p[i] == '-' || bog->p[i] == '0')
			i++;
		while (bog->p[i] == ' ')
			i++;
		i--;
		if (bog->p[i] == ' ')
		{
			i++;
			if (bog->p[i] == '-' || bog->p[i] == '0')
				i++;
			bog->s = ((bog->p[i] != '+')
					? ft_strjoin_fix(" ", bog->s, 1) : bog->s);
		}
	}
}

void	ft_hash_plus(t_printf *bog, size_t i)
{
	int		k;

	while (bog->p[i] == '-' || bog->p[i] == '0')
		i++;
	if (bog->s && bog->p[i] == '#' && (bog->c == 'f' || bog->c == 'F'))
	{
		k = 0;
		while (bog->s[k] && bog->s[k] != '.')
			k++;
		if (k == (int)ft_strlen(bog->s))
			bog->s = ft_strjoin_fix(bog->s, ".", 2);
	}
	if (bog->s && bog->p[i] == '#' && ft_strchr("xX", bog->c)
										&& ft_atoi(bog->s) > 0)
		bog->s = (bog->c == 'x' ? ft_strjoin_fix("0x", bog->s, 1)
									: ft_strjoin_fix("0X", bog->s, 1));
	if (bog->p[i] == '#' && (bog->c == 'o' || bog->c == 'O'))
		bog->s = (ft_strcmp(bog->s, "0") != 0)
				? ft_strjoin_fix("0", bog->s, 1) : bog->s;
	i = 0;
	while (bog->p[i] == '-' || bog->p[i] == '0' || bog->p[i] == ' ')
		i++;
	if (bog->s && bog->p[i] == '+' && ft_strchr("idfIDF", bog->c))
		bog->s = (ft_atoi(bog->s) >= 0
				? ft_strjoin_fix("+", bog->s, 1) : bog->s);
}
