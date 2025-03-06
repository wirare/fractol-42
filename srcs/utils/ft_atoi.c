/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:09:19 by ellanglo          #+#    #+#             */
/*   Updated: 2025/02/11 15:58:36 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

static int	isspace(int c)
{
	return (c == ' ' || (unsigned int)c - '\t' < 0x5);
}

int	ref_atoi(const char *str, int *dest)
{
	long	result;
	int		sign;
	char	*str_cp;

	str_cp = (char *)str;
	result = 0;
	while (isspace(*str_cp))
		str_cp++;
	sign = (*str_cp != '-') - (*str_cp == '-');
	str_cp += (*str_cp == '+') || (*str_cp == '-');
	if (!*str_cp)
		return (1);
	while (*str_cp)
	{
		if (*str_cp == '.')
			break ;
		if (!ft_isdigit(*str_cp))
			return (1);
		result = result * 10 + (*str_cp++ - '0');
		if ((sign == 1 && result > 2147483647) || result > 2147483648)
			return (1);
	}
	*dest = result * sign;
	return (0);
}
