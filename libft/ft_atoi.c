/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:02:05 by bkuksa            #+#    #+#             */
/*   Updated: 2018/11/05 19:07:42 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	i;

	sign = 1;
	i = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		++str;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		++str;
	while ((*str != '\0') && (*str >= '0' && *str <= '9'))
	{
		i = (i * 10) + (*str - '0');
		if (i >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (i > 9223372036854775807 && sign == -1)
			return (0);
		++str;
	}
	return ((int)(i * sign));
}
