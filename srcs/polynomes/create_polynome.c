/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_polynome.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:45:36 by ellanglo          #+#    #+#             */
/*   Updated: 2025/02/11 16:13:48 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "polynomes.h"
#include "app_handler.h"
#include <stdlib.h>
#include <unistd.h>

void	free_poly(t_polynomeN_info *poly)
{
	free(poly->root);
	free(poly->derivative.coef);
	free(poly->polynomes.coef);
}

t_polynomeN	init_poly_n(double *coef, int degree)
{
	t_polynomeN	polynome;

	polynome.degree = degree;
	degree++;
	polynome.coef = malloc(degree * sizeof(float));
	if (polynome.coef)
	{
		while (degree)
		{
			polynome.coef[polynome.degree + 1 - degree] = *coef;
			coef++;
			degree--;
		}
	}
	return (polynome);
}

t_polynomeN_info	init_poly_n_info(t_polynomeN polynome)
{
	t_polynomeN_info	i_poly;

	i_poly.polynomes = polynome;
	i_poly.flag = 0;
	if (polynome.degree == 3)
	{
		i_poly.root = malloc(3 * sizeof(t_complex));
		if (__builtin_expect(i_poly.root == NULL, 0))
		{
			i_poly.flag = 1;
			return (i_poly);
		}
		find_cubic_root(&i_poly);
	}
	if (__builtin_expect(derivative_calc(&i_poly), 0))
		i_poly.flag = 1;
	return (i_poly);
}

int	set_poly(t_newton_fractal *fractal, double *poly)
{
	t_polynomeN			polynome;

	polynome = init_poly_n(poly, 3);
	if (__builtin_expect(polynome.coef == NULL, 0))
	{
		write(2, "Malloc error, exit\n", 19);
		return (1);
	}
	fractal->polynome = init_poly_n_info(polynome);
	if (__builtin_expect(fractal->polynome.flag, 0))
	{
		free_poly(&fractal->polynome);
		write(2, "Malloc error, exit\n", 19);
		return (1);
	}
	return (0);
}
