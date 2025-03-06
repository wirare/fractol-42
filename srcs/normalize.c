/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:10:47 by ellanglo          #+#    #+#             */
/*   Updated: 2024/12/14 23:16:16 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "normalize.h"

double __attribute__((const))	normalize_x(double pos_x, double z_l)
{
	double	ar;
	double	min;
	double	max;

	ar = (double)LENGTH / HEIGHT;
	min = -2 * ar * z_l;
	max = -min;
	pos_x = min + ((double)pos_x / LENGTH) * (max - min);
	return (pos_x);
}

double __attribute__((const))	normalize_y(double pos_y, double z_l)
{
	double	min;
	double	max;

	min = -2 * z_l;
	max = -min;
	pos_y = min + ((double)pos_y / HEIGHT) * (max - min);
	return (pos_y);
}
