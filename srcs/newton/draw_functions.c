/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:20:18 by ellanglo          #+#    #+#             */
/*   Updated: 2025/03/13 17:14:52 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include "app_handler.h"
#include "mlx.h"
#include "newton.h"

__attribute__((const))
inline t_color	get_color(int nb)
{
	if (nb == 0)
		return (0xFFD9A5B3);
	if (nb == 1)
		return (0xFF1868AE);
	return (0xFFC6D7EB);
}

void	draw_pixel(t_app *app, t_complex z, t_complex pos)
{
	static t_color		pixel[LENGTH + HEIGHT];
	t_color				color;
	t_newton_fractal	fractal;

	fractal = app->n_env;
	if ((int)pos.re % fractal.p_f == 0 && (int)pos.im % fractal.p_f == 0)
	{
		color = newton_full(fractal, z);
		pixel[(int)pos.im / fractal.p_f] = color;
	}
	else
		color = pixel[(int)pos.im / fractal.p_f];
	mlx_set_image_pixel(app->mlx, app->img, pos.re, pos.im, color);
}
