/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:51:40 by bkuksa            #+#    #+#             */
/*   Updated: 2019/03/19 17:45:01 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *form, ...)
{
	int			cr;
	int			val;
	int			count;
	t_printf	bog;

	count = 0;
	val = 0;
	va_start(bog.arg, form);
	cr = ft_printf_all(form, &bog, count, val);
	va_end(bog.arg);
	return (cr);
}

int		ft_printf_all(const char *form, t_printf *bog, int count, int val)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (form[i])
	{
		j = i;
		ft_bog_upp(bog);
		if (form[i] == '%')
		{
			i++;
			ft_app_col(form, i, bog);
			val = ft_valid_bog(form, &i);
			if (val == -3)
				i++;
			if (val == 1)
				val = -7;
		}
		else
			while (form[i] && form[i] != '%')
				i++;
		count = count + ft_sharing(form + j, i - j, val, bog);
		ft_strdel(&(bog->p));
	}
	return (count);
}

int		ft_sharing(const char *str, size_t len, int val, t_printf *bog)
{
	if (*str == '%' && val == -7)
		return (ft_bog_list(bog));
	if (*str != '%')
		return (ft_write(str, len, bog));
	return (0);
}
