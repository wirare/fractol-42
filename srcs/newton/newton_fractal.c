/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:27:59 by ellanglo          #+#    #+#             */
/*   Updated: 2025/03/13 16:50:56 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include "app_handler.h"
#include "newton.h"
#include "normalize.h"

static inline void	evaluate_polynome(t_polynomeN poly, t_complex z, t_complex *result)
{
	int			i;

	*result = (t_complex){.re = poly.coef[0], .im = 0};
	i = 1;
	while (i <= poly.degree)
	{
		z_mult(result, z);
		z_add(result, (t_complex){.re = poly.coef[i], .im = 0});
		i++;
	}
}

static void	newton_step(t_polynomeN_info polynome, t_complex *z)
{
	t_complex	z_derivative;
	t_complex	z_polynome;
	t_complex	zd_over_zp;

	evaluate_polynome(polynome.derivative, *z, &z_derivative);
	evaluate_polynome(polynome.polynomes, *z, &z_polynome);
	z_divide(&z_polynome, z_derivative);
	zd_over_zp = z_polynome;
	zd_over_zp.re = -zd_over_zp.re;
	zd_over_zp.im = -zd_over_zp.im;
	z_add(z, zd_over_zp);
}

__attribute__((const))
t_color	newton_full(t_newton_fractal fractal, t_complex z)
{
	int					i;
	uint8_t				color;
	t_polynomeN_info	polynome;

	i = 0;
	polynome = fractal.polynome;
	while (i < fractal.iteration && \
		closest_root(polynome.root, z, polynome.polynomes.degree, 0) > 0.00001)
	{
		newton_step(polynome, &z);
		i++;
	}
	color = closest_root(polynome.root, z, polynome.polynomes.degree, 1);
	return (get_color(color));
}

void		call_newton(t_app *app)
{
	t_complex			complexe;
	t_complex			pos;
	t_newton_fractal	fractal;
	static double		ys[1920] = {0};

	fractal = app->n_env;
	pos.re = 0;
	while (pos.re < LENGTH)
	{
		pos.im = 0;
		complexe.re = normalize_x(pos.re, fractal.zoom_level);
		complexe.re += fractal.zoom_offset.re;
		while (pos.im < HEIGHT)
		{
			if (pos.re == 0)
				ys[(int)pos.im] = normalize_y(pos.im, fractal.zoom_level);
			complexe.im = ys[(int)pos.im] + fractal.zoom_offset.im;
			draw_pixel(app, complexe, pos);
			pos.im++;
		}
		pos.re++;
	}
}
