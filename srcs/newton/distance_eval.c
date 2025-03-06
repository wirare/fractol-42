/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_eval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:22:18 by ellanglo          #+#    #+#             */
/*   Updated: 2024/12/14 23:16:45 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "newton.h"

__attribute__((const))
static double	compute_distance(t_complex z, t_complex root)
{
	double	re_distance;
	double	im_distance;

	re_distance = root.re - z.re;
	im_distance = root.im - z.im;
	return (re_distance * re_distance + im_distance * im_distance);
}

double	closest_root(t_complex *root, t_complex z, int degree, int mode)
{
	double	current_distance;
	double	smallest_distance;
	uint8_t	smallest_distance_index;

	smallest_distance = 1e10;
	smallest_distance_index = 5;
	degree--;
	while (degree >= 0)
	{
		current_distance = compute_distance(z, root[degree]);
		if (current_distance < smallest_distance)
		{
			smallest_distance = current_distance;
			smallest_distance_index = degree;
		}
		degree--;
	}
	if (mode)
		return (smallest_distance_index);
	else
		return (smallest_distance);
}
