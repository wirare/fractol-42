/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:59:28 by ellanglo          #+#    #+#             */
/*   Updated: 2025/03/15 10:30:49 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "app_handler.h"
#include "mlx.h"
#include <stdint.h>
#include <stdlib.h>

void	app_init(t_app *app, t_fractal env, t_newton_fractal n_env)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		app_destroy(app, 1);
	app->win = mlx_new_window(app->mlx, LENGTH, HEIGHT, NAME);
	if (!app->win)
		app_destroy(app, 2);
	app->img = mlx_new_image(app->mlx, LENGTH, HEIGHT);
	if (!app->img)
		app_destroy(app, 3);
	if (app->type == 1)
		app->env = env;
	else
		app->n_env = n_env;
}

void	app_destroy(t_app *app, int code)
{
	if (app->type == 0)
		free_poly(&app->n_env.polynome);
	if (app->mlx)
	{
		if (app->win)
			mlx_clear_window(app->mlx, app->win);
		if (app->img)
			mlx_destroy_image(app->mlx, app->img);
		if (app->win)
			mlx_destroy_window(app->mlx, app->win);
		mlx_destroy_display(app->mlx);
	}
	exit(code);
}

void	event_handler(t_app *app)
{
	if (app->type == 1)
	{
		mlx_on_event(app->mlx, app->win, MLX_KEYDOWN, key_hook, app);
		mlx_on_event(app->mlx, app->win, MLX_MOUSEWHEEL, wheel_hook, app);
		mlx_on_event(app->mlx, app->win, MLX_MOUSEDOWN, mouse_hook, app);
	}
	else
	{
		mlx_on_event(app->mlx, app->win, MLX_KEYDOWN, n_key_hook, app);
		mlx_on_event(app->mlx, app->win, MLX_MOUSEWHEEL, n_wheel_hook, app);
	}
	mlx_on_event(app->mlx, app->win, MLX_WINDOW_EVENT, window_hook, app->mlx);
}
