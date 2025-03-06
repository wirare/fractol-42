/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derivative_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:56:33 by ellanglo          #+#    #+#             */
/*   Updated: 2024/12/14 23:16:54 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "polynomes.h"
#include <stdlib.h>

int	derivative_calc(t_polynomeN_info *polynomes)
{
	int			i;
	int			degree;
	t_polynomeN	poly;

	poly = polynomes->polynomes;
	degree = poly.degree;
	polynomes->derivative.coef = malloc(degree * sizeof(float));
	if (__builtin_expect(polynomes->derivative.coef == NULL, 0))
		return (1);
	i = 0;
	polynomes->derivative.degree = degree - 1;
	while (degree)
	{
		polynomes->derivative.coef[i] = poly.coef[i] * (degree);
		degree--;
		i++;
	}
	return (0);
}
