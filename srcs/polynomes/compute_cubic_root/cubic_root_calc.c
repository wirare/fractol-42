/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic_root_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:29:27 by ellanglo          #+#    #+#             */
/*   Updated: 2024/12/14 23:16:50 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "complex_number.h"
#include "polynomes.h"
#include <math.h>

static void	shift(t_polynomeN_info *polynomes)
{
	double		shift;
	t_polynomeN	poly;

	poly = polynomes->polynomes;
	shift = poly.coef[1] / (3 * poly.coef[0]);
	polynomes->root[0].re -= shift;
	polynomes->root[1].re -= shift;
	polynomes->root[2].re -= shift;
}

static void	delta_m_0(double q, double delta, t_polynomeN_info *polynomes)
{
	double	u;
	double	v;

	u = calc_u(delta, q);
	v = calc_v(delta, q);
	polynomes->root[0] = (t_complex){u + v, 0, 0};
	polynomes->root[1].re = -(u + v) / 2;
	polynomes->root[1].im = sqrt(3) * (u - v) / 2;
	polynomes->root[2].re = -(u + v) / 2;
	polynomes->root[2].im = -sqrt(3) * (u - v) / 2;
}

static void	delta_l_0(double p, double q, t_polynomeN_info *polynomes)
{
	double	r;
	double	phi;
	double	t;

	r = sqrt(-((p / 3) * (p / 3) * (p / 3)));
	phi = acos(-q / (2 * r));
	t = 2 * cbrt(r);
	polynomes->root[0] = (t_complex){t * cos(phi / 3), 0, 0};
	polynomes->root[1] = (t_complex){t * cos((phi + 2 * M_PI) / 3), 0, 0};
	polynomes->root[2] = (t_complex){t * cos((phi + 4 * M_PI) / 3), 0, 0};
}

static void	delta_e_0(double q, t_polynomeN_info *polynomes)
{
	double	u;

	if (q != 0)
		u = 0;
	else
		u = cbrt(-q / 2);
	polynomes->root[0] = (t_complex){2 * u, 0, 0};
	polynomes->root[1] = (t_complex){-u, 0, 0};
	polynomes->root[2] = (t_complex){-u, 0, 0};
}

void	find_cubic_root(t_polynomeN_info *polynomes)
{
	double	p;
	double	q;
	double	delta;

	p = calc_p(polynomes->polynomes);
	q = calc_q(polynomes->polynomes);
	delta = calc_delta(q, p);
	if (delta > 0)
		delta_m_0(q, delta, polynomes);
	else if (delta < 0)
		delta_l_0(p, q, polynomes);
	else
		delta_e_0(q, polynomes);
	shift(polynomes);
}
