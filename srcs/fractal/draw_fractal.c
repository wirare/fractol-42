/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:23:31 by ellanglo          #+#    #+#             */
/*   Updated: 2025/03/15 10:31:52 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "complex_number.h"
#include "fractol.h"
#include "app_handler.h"
#include "normalize.h"
#include "mlx.h"
#include <stdint.h>

static void	set_color_offset(t_app *app)
{
	static uint16_t	offset = 0;

	if (app->env.c_offset_mode)
	{
		if (app->env.c_offset_mode == -1 && offset < 1)
			offset = 1024;
		else if (app->env.c_offset_mode == 1 && offset > 1024)
			offset = 0;
		else
			offset += app->env.c_offset_mode;
	}
	else
		offset = 0;
	app->env.c_offset = offset;
}

void	draw_call(t_app *app)
{
	t_complex		complexe;
	t_complex		pos;
	t_fractal		fractal;
	static double	ys[1920] = {0};

	fractal = app->env;
	pos.re = 0;
	set_color_offset(app);
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
			fractal.__draw_fuction(app, complexe, pos);
			pos.im++;
		}
		pos.re++;
	}
}

void	follow_mouse(t_app *app)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(app->mlx, &x, &y);
	app->env.c.re = normalize_x(x, app->env.zoom_level);
	app->env.c.im = normalize_y(y, app->env.zoom_level);
	draw_call(app);
}

void	draw_fractal(t_app *app, t_complex z, t_complex c, t_complex pos)
{
	static t_color	pixel[LENGTH * HEIGHT] = {0};
	t_color			color;
	t_fractal		fractal;

	fractal = app->env;
	if ((int)pos.re % fractal.p_f == 0 && (int)pos.im % fractal.p_f == 0)
	{
		color = julia(z, c, fractal);
		pixel[(int)pos.im / fractal.p_f] = color;
	}
	else
		color = pixel[(int)pos.im / fractal.p_f];
	mlx_set_image_pixel(app->mlx, app->img, pos.re, pos.im, color);
}
