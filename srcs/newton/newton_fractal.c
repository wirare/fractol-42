/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:27:59 by ellanglo          #+#    #+#             */
/*   Updated: 2025/02/11 16:24:25 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include "app_handler.h"
#include "newton.h"
#include "normalize.h"

t_complex	evaluate_polynome(t_polynomeN poly, t_complex z)
{
	t_complex	result;
	int			i;

	result = z_init(poly.coef[0], 0);
	i = 1;
	while (i <= poly.degree)
	{
		result = z_mult(result, z);
		result = z_add(result, z_init(poly.coef[i], 0));
		i++;
	}
	return (result);
}

__attribute__((const))
static t_complex	newton_step(t_polynomeN_info polynome, t_complex z)
{
	t_complex	z_derivative;
	t_complex	z_polynome;
	t_complex	zd_over_zp;

	z_derivative = evaluate_polynome(polynome.derivative, z);
	z_polynome = evaluate_polynome(polynome.polynomes, z);
	zd_over_zp = z_divide(z_polynome, z_derivative);
	zd_over_zp.re = -zd_over_zp.re;
	zd_over_zp.im = -zd_over_zp.im;
	return (z_add(z, zd_over_zp));
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
		z = newton_step(polynome, z);
		i++;
	}
	color = closest_root(polynome.root, z, polynome.polynomes.degree, 1);
	return (get_color(color));
}

void	call_newton(t_app *app)
{
	int					pos_x;
	int					pos_y;
	double				re;
	double				im;
	t_newton_fractal	fractal;

	fractal = app->n_env;
	pos_x = 0;
	while (pos_x < LENGTH)
	{
		pos_y = 0;
		re = normalize_x(pos_x, fractal.zoom_level) + fractal.zoom_offset.re;
		while (pos_y < HEIGHT)
		{
			im = normalize_y(pos_y, fractal.zoom_level);
			im += fractal.zoom_offset.im;
			draw_pixel(app, z_init(re, im), z_init(pos_x, pos_y));
			pos_y++;
		}
		pos_x++;
	}
}
