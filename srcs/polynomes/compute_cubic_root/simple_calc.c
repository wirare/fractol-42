/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:42:00 by ellanglo          #+#    #+#             */
/*   Updated: 2024/12/14 23:16:51 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "polynomes.h"
#include <math.h>

__attribute__((const))
double	calc_delta(double q, double p)
{
	double	delta;

	delta = (q / 2) * (q / 2);
	delta += (p / 3) * (p / 3) * (p / 3);
	return (delta);
}

__attribute__((const))
double	calc_p(t_polynomeN poly)
{
	double	p;

	p = (3 * poly.coef[0] * poly.coef[2]) - ((poly.coef[1]) * (poly.coef[1]));
	p /= 3 * (poly.coef[0] * poly.coef[0]);
	return (p);
}

__attribute__((const))
double	calc_q(t_polynomeN poly)
{
	double	q;

	q = 2 * (poly.coef[1] * poly.coef[1] * poly.coef[1]);
	q /= 27 * (poly.coef[0] * poly.coef[0] * poly.coef[0]);
	q -= (poly.coef[1] * poly.coef[2]) / (3 * (poly.coef[0] * poly.coef[0]));
	q += poly.coef[3] / poly.coef[0];
	return (q);
}

__attribute__((const))
double	calc_u(double delta, double q)
{
	double	u;

	u = (-q / 2) + sqrt(delta);
	u = cbrt(u);
	return (u);
}

__attribute__((const))
double	calc_v(double delta, double q)
{
	double	v;

	v = (-q / 2) - sqrt(delta);
	v = cbrt(v);
	return (v);
}
