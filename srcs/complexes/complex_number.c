/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:48:23 by ellanglo          #+#    #+#             */
/*   Updated: 2025/03/13 17:25:08 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "complex_number.h"
#include <math.h>

__attribute__((always_inline))
inline void z_add(t_complex *z1, t_complex z2)
{
	t_complex	z_res;

	z_res.re = z1->re + z2.re;
	z_res.im = z1->im + z2.im;
	*z1 = z_res;
}

inline void	z_power(t_complex *z, int power)
{
	t_complex	z_res;
	double		re_im_3;
	double		im_cube;
	double		re_cube;

	if (power == 1)
	{
		z_res.im = fabs(2 * z->re * z->im);
		z_res.re = z->re * z->re - z->im * z->im;
	}
	else if (power == 2)
	{
		z_res.im = 2 * z->re * z->im;
		z_res.re = z->re * z->re - z->im * z->im;
	}
	else
	{
		re_im_3 = 3 * z->re * z->im;
		re_cube = z->re * z->re * z->re;
		im_cube = z->im * z->im * z->im;
		z_res.re = re_cube - (re_im_3 * z->im);
		z_res.im = (re_im_3 * z->re) - im_cube;
	}
	*z = z_res;
}

__attribute__((always_inline))
inline double	mod2(t_complex z)
{
	return (z.re * z.re + z.im * z.im);
}

__attribute__((always_inline))
inline void	z_mult(t_complex *z1, t_complex z2)
{
	t_complex	z_res;

	z_res.re = (z1->re * z2.re) - (z1->im * z2.im);
	z_res.im = (z1->re * z2.im) + (z1->im * z2.re);
	*z1 = z_res;
}

__attribute__((always_inline))
inline void	z_divide(t_complex *z1, t_complex z2)
{
	t_complex	z_res;
	double		c2_plus_d2;

	c2_plus_d2 = (z2.re * z2.re) + (z2.im * z2.im);
	z_res.re = (z1->re * z2.re) + (z1->im * z2.im);
	z_res.re /= c2_plus_d2;
	z_res.im = (z1->im * z2.re) - (z1->re * z2.im);
	z_res.im /= c2_plus_d2;
	*z1 = z_res;
}
