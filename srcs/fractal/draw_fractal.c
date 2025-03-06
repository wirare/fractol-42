/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:23:31 by ellanglo          #+#    #+#             */
/*   Updated: 2025/02/26 17:26:53 by ellanglo         ###   ########.fr       */
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
	int			pos_x;
	int			pos_y;
	double		re;
	double		im;
	t_fractal	fractal;

	fractal = app->env;
	pos_x = 0;
	set_color_offset(app);
	while (pos_x < LENGTH)
	{
		pos_y = 0;
		re = normalize_x(pos_x, fractal.zoom_level);
		re += fractal.zoom_offset.re;
		while (pos_y < HEIGHT)
		{
			im = normalize_y(pos_y, fractal.zoom_level);
			im += fractal.zoom_offset.im;
			fractal.__draw_fuction(app, z_init(re, im), z_init(pos_x, pos_y));
			pos_y++;
		}
		pos_x++;
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
	static t_color	pixel[LENGTH + HEIGHT];
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
