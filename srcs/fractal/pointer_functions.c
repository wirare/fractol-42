/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:16:12 by ellanglo          #+#    #+#             */
/*   Updated: 2025/03/11 18:04:15 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include "app_handler.h"

void	__draw_mandelbrot(t_app *app, t_complex z1, t_complex pos)
{
	draw_fractal(app, (t_complex){.re = 0, .im = 0}, z1, pos);
}

void	__draw_julia(t_app *app, t_complex z1, t_complex pos)
{
	draw_fractal(app, z1, app->env.c, pos);
}
