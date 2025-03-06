/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 01:43:58 by ellanglo          #+#    #+#             */
/*   Updated: 2025/02/26 17:15:45 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

# include "complex_number.h"
# include "gradient/gradient_table.h"
# include "gradient/gradient_table1.h"
# include "gradient/gradient_table2.h"
# include "app_handler.h"
# include <stdint.h>

typedef uint32_t	t_color;

t_color	julia(t_complex z, t_complex c, t_fractal fractal);
void	__draw_mandelbrot(t_app *app, t_complex z1, t_complex z2);
void	__draw_julia(t_app *app, t_complex z1, t_complex z2);
void	follow_mouse(t_app *app);
void	draw_call(t_app *app);
void	draw_fractal(t_app *app, t_complex z, t_complex c, t_complex pos);
#endif
