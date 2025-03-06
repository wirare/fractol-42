/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_key_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:12:00 by ellanglo          #+#    #+#             */
/*   Updated: 2024/12/14 23:16:20 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "app_handler.h"
#include <SDL2/SDL_scancode.h>

static void	n_backspace(t_app *app)
{
	app->n_env.iteration = 128;
	app->n_env.p_f = 1;
	app->n_env.zoom_level = 1;
	app->n_env.zoom_offset = z_init(0, 0);
}

static void	n_zoom(int key, t_app *app)
{
	if (key == SDL_SCANCODE_UP)
		app->n_env.zoom_offset.im -= app->n_env.zoom_level;
	if (key == SDL_SCANCODE_DOWN)
		app->n_env.zoom_offset.im += app->n_env.zoom_level;
	if (key == SDL_SCANCODE_LEFT)
		app->n_env.zoom_offset.re -= app->n_env.zoom_level;
	if (key == SDL_SCANCODE_RIGHT)
		app->n_env.zoom_offset.re += app->n_env.zoom_level;
}

static void	n_quality(int key, t_app *app)
{
	if (key == SDL_SCANCODE_DELETE)
		app->n_env.p_f = 1;
	if (key == SDL_SCANCODE_PAGEUP && app->n_env.p_f < 16)
		app->n_env.p_f++;
	if (key == SDL_SCANCODE_PAGEDOWN && app->n_env.p_f > 1)
		app->n_env.p_f--;
	if (key == SDL_SCANCODE_COMMA && app->n_env.iteration < 1014)
		app->n_env.iteration += 10;
	if (key == SDL_SCANCODE_PERIOD && app->n_env.iteration > 10)
		app->n_env.iteration -= 10;
}

int	n_key_hook(int key, void *_app)
{
	t_app		*app;

	app = (t_app *)_app;
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(app->mlx);
	n_quality(key, app);
	n_zoom(key, app);
	if (key == SDL_SCANCODE_BACKSPACE)
		n_backspace(app);
	return (0);
}
