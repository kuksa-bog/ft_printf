/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_bog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:34:55 by bkuksa            #+#    #+#             */
/*   Updated: 2019/02/27 18:11:57 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_valid(const char c)
{
	if (ft_conversion(c) || ft_isdigit(c) || ft_flag(c) || ft_precision(c)
		|| ft_mod(c))
		return (1);
	return (0);
}

int		ft_conversion(const char c)
{
	if (ft_strchr("cdDpPiIsSCxXoOuUfF%", c) != NULL)
		return (1);
	return (0);
}

int		ft_flag(const char c)
{
	if (ft_strchr("#0-+ ", c) != NULL)
		return (1);
	return (0);
}

int		ft_precision(const char c)
{
	if (ft_strchr(".0123456789", c) != NULL)
		return (1);
	return (0);
}

int		ft_mod(const char c)
{
	if (ft_strchr("hl", c) != NULL)
		return (1);
	return (0);
}
