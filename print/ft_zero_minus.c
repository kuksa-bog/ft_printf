/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:55:23 by bkuksa            #+#    #+#             */
/*   Updated: 2019/03/28 12:47:00 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus(t_printf *bog, size_t i)
{
	char	*str;
	int		j;
	int		k;
	int		c;

	j = -1;
	while (ft_strchr("#+0", bog->p[i]))
		i++;
	if (bog->p[i] == '-' && (str = ft_strnew(11)))
	{
		i++;
		while (bog->p[i] == '#' || bog->p[i] == '+' || bog->p[i] == ' ')
			i++;
		while (bog->p[i] == '-')
			i++;
		while (bog->p[i] >= '0' && bog->p[i] <= '9')
			str[++j] = bog->p[i++];
		j = ft_atoi(str);
		ft_strdel(&str);
		k = (int)ft_strlen(bog->s);
		c = 1;
		if (k < j)
			bog->s = ft_str_minus(j - k, bog, c);
	}
}

void	ft_int_s(t_printf *bog, size_t i)
{
	int		j;
	int		k;
	int		c;
	char	*str;

	str = ft_strnew(11);
	j = -1;
	if (bog->p[i] == '0' && bog->tup != 1)
		ft_zero(bog, i, -1);
	else
	{
		while (ft_strchr("#+ ", bog->p[i]))
			i++;
		while (bog->p[i] >= '0' && bog->p[i] <= '9')
			str[++j] = bog->p[i++];
		j = ft_atoi(str);
		k = (int)ft_strlen(bog->s);
		c = 0;
		if (k < j)
			bog->s = ft_str_minus(j - k, bog, c);
	}
	ft_strdel(&str);
}

char	*ft_str_minus(int k, t_printf *bog, int c)
{
	int		i;
	char	*str;
	int		j;

	j = -1;
	if (bog->n == 0)
		k += 1;
	i = -1;
	bog->n_spec = 1;
	str = ft_strnew(ft_strlen(bog->s) + k);
	while (--k && c == 0)
		str[++j] = ' ';
	while (bog->s && bog->s[++i])
		str[++j] = bog->s[i];
	++k;
	while (--k && c == 1)
		str[++j] = ' ';
	if ((ft_strchr("oOuUxXfFC", bog->c) && bog->s != NULL)
		|| (bog->c == 's' && bog->z > 0) || (bog->c == 'S' && bog->z == 0)
		|| (ft_strchr("cidIDpP", bog->c) && bog->min == 0))
		ft_strdel(&(bog->s));
	bog->s = str;
	return (bog->s);
}

void	ft_zero(t_printf *bog, size_t i, int k)
{
	int		j;
	char	*str;

	j = -1;
	while (bog->p[i] == '#' || bog->p[i] == '+' || bog->p[i] == ' ')
		i++;
	while (bog->p[i] == '0')
		i++;
	i--;
	if (bog->p[i] == '0' && (str = ft_strnew(11)))
	{
		i++;
		while (bog->p[i] == '#' || bog->p[i] == '+')
			i++;
		while (bog->p[i] >= '0' && bog->p[i] <= '9')
			str[++j] = bog->p[i++];
		j = ft_atoi(str);
		ft_strdel(&str);
		i = ft_strlen(bog->s);
		if (bog->tup == 1 && (int)i < j)
			bog->s = ft_str_minus(j - (int)i, bog, 0);
		if ((int)i < j)
			ft_str_zero(j - (int)i + 1, -1, bog, k);
	}
}

void	ft_str_zero(int i, int j, t_printf *bog, int k)
{
	int		r;
	char	*str;

	r = 0;
	if (bog->n == 1)
		i--;
	while (bog->p[r] == '-' || bog->p[r] == '0')
		r++;
	str = ft_strnew(ft_strlen(bog->s) + i);
	while ((bog->c == 'x' || bog->c == 'X')
	&& bog->p[r] == '#' && j + 1 <= 1 && ++j >= 0)
		str[j] = bog->s[j];
	if (ft_strchr(bog->p, '+') != 0 && ft_atoi(bog->s) >= 0 && j == -1 && k++)
		str[++j] = '+';
	if (ft_strchr("- ", bog->s[0]) != 0 && j == -1 && k++)
		str[++j] = (char)(bog->s[0] == '-' ? '-' : ' ');
	while ((bog->c != 'p' && bog->c != 'P') && bog->tup != 1 && --i)
		str[++j] = '0';
	while ((bog->c == 'p' || bog->c == 'P') && ++j >= 0 && bog->s[k + 1])
		str[j] = (char)((j <= 1 || j >= 1 + i) ? bog->s[++k] : '0');
	if (((bog->c == 'x' || bog->c == 'X') && bog->p[r] == '#'))
		k += 2;
	while ((bog->c != 'p' && bog->c != 'P') && bog->s[++k])
		str[++j] = bog->s[k];
	ft_del_bog_s(bog, str);
}
