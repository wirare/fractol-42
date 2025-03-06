/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:12:22 by ellanglo          #+#    #+#             */
/*   Updated: 2025/02/11 16:17:39 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

int	ref_atof(const char *str, double *nb)
{
	double	decimals;
	int		temp;
	int		sign;
	int		len;

	decimals = 0;
	len = 0;
	sign = (*str != '-') - (*str == '-');
	str += (*str == '+') || (*str == '-');
	if (ref_atoi(str, &temp))
		return (1);
	*nb = temp;
	str = ft_strchr(str, '.');
	if (str && *(str + 1))
	{
		str++;
		if (ref_atoi(str, &temp))
			return (1);
		while (ft_isdigit(str[len]))
			len++;
		decimals = (double)temp / power(10, len);
	}
	*nb = sign * (*nb + decimals);
	return (0);
}
