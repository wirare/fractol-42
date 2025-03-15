/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:43:01 by ellanglo          #+#    #+#             */
/*   Updated: 2025/03/15 10:29:13 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "app_handler.h"
#include "fractol.h"
#include <mlx.h>
#include <SDL2/SDL_scancode.h>

void	backspace(t_app *app)
{
	app->env.iteration = 128;
	app->env.p_f = 1;
	app->env.mode = 2;
	app->env.c_offset_mode = 0;
	app->env.zoom_level = 1;
	app->env.zoom_offset = (t_complex){.re = 0, .im = 0};
}

void	zoom(int key, t_app *app)
{
	if (key == SDL_SCANCODE_UP)
		app->env.zoom_offset.im -= app->env.zoom_level;
	if (key == SDL_SCANCODE_DOWN)
		app->env.zoom_offset.im += app->env.zoom_level;
	if (key == SDL_SCANCODE_LEFT)
		app->env.zoom_offset.re -= app->env.zoom_level;
	if (key == SDL_SCANCODE_RIGHT)
		app->env.zoom_offset.re += app->env.zoom_level;
}

void	quality(int key, t_app *app)
{
	if (key == SDL_SCANCODE_DELETE)
		app->env.p_f = 1;
	if (key == SDL_SCANCODE_PAGEUP && app->env.p_f < 16)
		app->env.p_f++;
	if (key == SDL_SCANCODE_PAGEDOWN && app->env.p_f > 1)
		app->env.p_f--;
	if (key == SDL_SCANCODE_PERIOD && app->env.iteration < 1014)
		app->env.iteration += 10;
	if (key == SDL_SCANCODE_COMMA && app->env.iteration > 10)
		app->env.iteration -= 10;
}

void	color(int key, t_app *app)
{
	if (key == SDL_SCANCODE_Q)
		app->env.c_offset_mode -= 2;
	if (key == SDL_SCANCODE_W)
		app->env.c_offset_mode = 0;
	if (key == SDL_SCANCODE_E)
		app->env.c_offset_mode += 2;
	if (key == SDL_SCANCODE_8)
		app->env.color_table = 0;
	if (key == SDL_SCANCODE_9)
		app->env.color_table = 1;
	if (key == SDL_SCANCODE_0)
		app->env.color_table = 2;
}

int	key_hook(int key, void *_app)
{
	t_app		*app;

	app = (t_app *)_app;
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(app->mlx);
	quality(key, app);
	zoom(key, app);
	color(key, app);
	if (key == SDL_SCANCODE_BACKSPACE)
		backspace(app);
	if (key == SDL_SCANCODE_1)
	{
		app->env.__draw_fuction = __draw_mandelbrot;
		app->env.mouse_flag = 0;
	}
	if (key == SDL_SCANCODE_2)
	{
		app->env.__draw_fuction = __draw_julia;
		app->env.mouse_flag = 1;
	}
	if (key == SDL_SCANCODE_EQUALS && app->env.mode != 3)
		app->env.mode += 1;
	if (key == SDL_SCANCODE_MINUS && app->env.mode != 1)
		app->env.mode -= 1;
	return (0);
}
