/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:25:06 by ellanglo          #+#    #+#             */
/*   Updated: 2024/11/29 17:48:29 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef NEWTON_H
# define NEWTON_H

# include "app_handler.h"

typedef uint32_t	t_color;

double		closest_root(t_complex *root, t_complex z, int degree, int mode);
void		draw_pixel(t_app *app, t_complex z, t_complex pos);
void		draw_root(t_app *app, t_polynomeN_info polynome);
t_color		get_color(int nb);
t_color		newton_full(t_newton_fractal fractal, t_complex z);
void		call_newton(t_app *app);
#endif
