/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:41:37 by ellanglo          #+#    #+#             */
/*   Updated: 2025/01/28 20:05:01 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "app_handler.h"
#include "normalize.h"
#include "fractol.h"
#include <SDL2/SDL_scancode.h>

int	window_hook(int event, void *mlx)
{
	if (event == 0)
		mlx_loop_end(mlx);
	return (0);
}

static t_complex	get_mouse_pos(t_app *app)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(app->mlx, &x, &y);
	return ((t_complex){x, y, 0});
}

int	wheel_hook(int action, void *_app)
{
	t_app		*app;
	t_complex	pos;
	t_complex	npos;

	app = (t_app *)_app;
	pos = get_mouse_pos(app);
	npos.re = normalize_x(pos.re, app->env.zoom_level);
	npos.im = normalize_y(pos.im, app->env.zoom_level);
	if (action == 1)
		app->env.zoom_level /= 1.2;
	if (action == 2 && app->env.zoom_level != 1)
	{
		app->env.zoom_level *= 1.2;
		if (app->env.zoom_level > .9)
		{
			app->env.zoom_offset = z_init(0, 0);
			app->env.zoom_level = 1;
			return (0);
		}
	}
	npos.re = normalize_x(pos.re, app->env.zoom_level) - npos.re;
	npos.im = normalize_y(pos.im, app->env.zoom_level) - npos.im;
	app->env.zoom_offset.re -= npos.re;
	app->env.zoom_offset.im -= npos.im;
	return (0);
}

int	mouse_hook(int action, void *_app)
{
	t_app		*app;
	t_complex	pos;
	t_complex	cpos;

	app = (t_app *)_app;
	if (app->env.__draw_fuction == __draw_julia)
	{
		if (app->env.mouse_flag == 1 && action == 1)
		{
			pos = get_mouse_pos(app);
			cpos.re = normalize_x(pos.re, app->env.zoom_level);
			cpos.im = normalize_y(pos.im, app->env.zoom_level);
			app->env.c = cpos;
			app->env.mouse_flag = 0;
		}
		else if (app->env.mouse_flag == 0 && action == 3)
			app->env.mouse_flag = 1;
	}
	return (0);
}

int	n_wheel_hook(int action, void *_app)
{
	t_app		*app;
	t_complex	pos;
	t_complex	npos;

	app = (t_app *)_app;
	pos = get_mouse_pos(app);
	npos.re = normalize_x(pos.re, app->n_env.zoom_level);
	npos.im = normalize_y(pos.im, app->n_env.zoom_level);
	if (action == 1)
		app->n_env.zoom_level /= 1.2;
	if (action == 2 && app->n_env.zoom_level != 10)
	{
		app->n_env.zoom_level *= 1.2;
		if (app->n_env.zoom_level > 10)
		{
			app->n_env.zoom_offset = z_init(0, 0);
			app->n_env.zoom_level = 10;
			return (0);
		}
	}
	npos.re = normalize_x(pos.re, app->n_env.zoom_level) - npos.re;
	npos.im = normalize_y(pos.im, app->n_env.zoom_level) - npos.im;
	app->n_env.zoom_offset.re -= npos.re;
	app->n_env.zoom_offset.im -= npos.im;
	return (0);
}
