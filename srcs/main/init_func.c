/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:27:23 by ellanglo          #+#    #+#             */
/*   Updated: 2025/02/26 17:16:07 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "app_handler.h"
#include "fractol.h"
#include "utils.h"

int	init_julia(int ac, char **av, t_fractal *fractal)
{
	if (ac != 4)
		return (1);
	if (ref_atof(av[2], &fractal->c.re) || ref_atof(av[3], &fractal->c.im))
		return (1);
	fractal->__draw_fuction = __draw_julia;
	return (0);
}

void	init_fractal(t_fractal *fractal)
{
	fractal->p_f = 1;
	fractal->iteration = 128;
	fractal->mode = 2;
	fractal->c_offset_mode = 0;
	fractal->mouse_flag = 0;
	fractal->zoom_level = 1;
	fractal->color_table = 0;
}

void	init_newton(t_newton_fractal *fractal)
{
	fractal->p_f = 1;
	fractal->iteration = 64;
	fractal->zoom_level = 1;
}
