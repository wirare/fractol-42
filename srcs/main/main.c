/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:28:37 by ellanglo          #+#    #+#             */
/*   Updated: 2025/03/07 16:40:01 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "app_handler.h"
#include "mlx.h"
#include "fractol.h"
#include "newton.h"
#include "utils.h"
#include "polynomes.h"

static int	__update(void *_app)
{
	static t_fractal	previous_fractal = {0};
	t_app				*app;

	app = (t_app *)_app;
	if (app->env.mouse_flag == 1 || ft_memcmp((void *)&previous_fractal,
			(void *)&app->env, sizeof(t_fractal))
		|| app->env.c_offset_mode != 0)
	{
		if (app->env.mouse_flag == 1)
			follow_mouse(app);
		else
			draw_call(app);
		mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
		previous_fractal = app->env;
	}
	return (0);
}

static int	__update_n(void *_app)
{
	static t_newton_fractal	previous_fractal = {0};
	t_app					*app;

	app = (t_app *)_app;
	if (ft_memcmp((void *)&previous_fractal,
			(void *)&app->n_env, sizeof(t_newton_fractal)))
	{
		call_newton(app);
		mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
		previous_fractal = app->n_env;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_app	app;

	if (parse_input(ac, av, &app))
		return (0);
	mlx_set_fps_goal(app.mlx, FPS);
	event_handler(&app);
	if (app.type == 1)
		mlx_loop_hook(app.mlx, __update, &app);
	else
		mlx_loop_hook(app.mlx, __update_n, &app);
	mlx_loop(app.mlx);
	app_destroy(&app, 0);
}
