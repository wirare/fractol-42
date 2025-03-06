/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:59:39 by ellanglo          #+#    #+#             */
/*   Updated: 2025/02/26 17:26:45 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include <stdint.h>
#include "fractol.h"
#include "complex_number.h"
#include "gradient/gradient_table.h"
#include "gradient/gradient_table1.h"
#include "gradient/gradient_table2.h"

__attribute__((const))
static int	first_check(t_complex z)
{
	double	q;
	double	im_square;
	double	re_25;

	im_square = z.im * z.im;
	re_25 = z.re - 0.25;
	q = (re_25 * re_25) + im_square;
	q = q * (q + re_25);
	if (q <= 0.25 * im_square)
		return (1);
	return (0);
}

t_color	get_color_table(int index, int table_index)
{
	static uint32_t	*color_table_0 = (uint32_t *)COLOR_TABLE_0;
	static uint32_t	*color_table_1 = (uint32_t *)COLOR_TABLE_1;
	static uint32_t	*color_table_2 = (uint32_t *)COLOR_TABLE_2;

	if (!table_index)
		return (color_table_0[index]);
	if (table_index == 1)
		return (color_table_1[index]);
	return (color_table_2[index]);
}

__attribute__((const))
inline static double	mylog2(void)
{
	static double	log2var = 0;

	if (log2var == 0)
		log2var = log(2);
	return (log2var);
}

t_color	julia(t_complex z, t_complex c, t_fractal fractal)
{
	int		i;
	double	iter;
	double	log_zn;
	double	nu;
	t_color	color_index;

	i = 0;
	if (!fractal.mouse_flag && fractal.mode == 2 && first_check(c))
		return (0);
	while (mod2(z) < 8 && i != fractal.iteration)
	{
		z = z_add(z_power(z, fractal.mode), c);
		i++;
	}
	if (i < fractal.iteration)
	{
		log_zn = log(z.re * z.re + z.im * z.im) / 2.;
		nu = log(log_zn / mylog2()) / mylog2();
		iter = (double)i + 1 - nu;
		color_index = (double)(fmod(iter, 128) * 8);
		return (get_color_table((color_index + fractal.c_offset) \
					% 1024, fractal.color_table));
	}
	return (0);
}
