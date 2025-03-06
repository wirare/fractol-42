/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:19:43 by ellanglo          #+#    #+#             */
/*   Updated: 2025/02/11 19:58:38 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "app_handler.h"
#include "fractol.h"
#include "utils.h"
#include <unistd.h>

int	newton_parsing(int ac, char **av, t_newton_fractal *fractal)
{
	int		i;
	double	poly[4];

	i = 0;
	av += 2;
	if (ac != 6)
	{
		print_error();
		return (-1);
	}
	while (i < 4)
	{
		if (ref_atof(*av, &poly[i]))
		{
			print_error();
			return (-1);
		}
		av++;
		i++;
	}
	init_newton(fractal);
	if (__builtin_expect(set_poly(fractal, poly), 0))
		return (1);
	return (0);
}

int	julia_parsing(t_fractal *fractal, int ac, char **av)
{
	int	av1_len;

	av1_len = ft_strlen(av[1]);
	if (ac > 1 && av1_len == 5 && !ft_strncmp(av[1], "julia", av1_len))
	{
		if (init_julia(ac, av, fractal))
			return (2);
	}
	else if (ac > 1 && av1_len == 5 && !ft_strncmp(av[1], "mouse", av1_len))
	{
		fractal->__draw_fuction = __draw_julia;
		fractal->mouse_flag = 1;
	}
	else
		return (1);
	return (0);
}

int	mandelbrot_parsing(t_fractal *fractal, int ac, char **av)
{
	int	av1_len;

	av1_len = ft_strlen(av[1]);
	if (ac > 1 && av1_len == 10 && !ft_strncmp(av[1], "mandelbrot", av1_len))
	{
		fractal->__draw_fuction = __draw_mandelbrot;
	}
	else if (ac > 1 && av1_len == 5 && !ft_strncmp(av[1], "bship", av1_len))
	{
		fractal->__draw_fuction = __draw_mandelbrot;
		fractal->mode = 1;
	}
	else
		return (1);
	return (0);
}

int	non_newton_parsing(int ac, char **av, t_fractal *fractal)
{
	int	return_code;

	init_fractal(fractal);
	return_code = julia_parsing(fractal, ac, av);
	if (return_code == 1)
	{
		return_code = mandelbrot_parsing(fractal, ac, av);
		if (return_code)
		{
			print_error();
			return (1);
		}
	}
	else if (return_code == 2)
	{
		print_error();
		return (1);
	}
	return (0);
}

int	parse_input(int ac, char **av, t_app *app)
{
	t_fractal			fractal;
	t_newton_fractal	n_frac;

	if (ac == 1)
	{
		print_error();
		return (1);
	}
	ft_memset((void *)&fractal, 0, sizeof(t_fractal));
	ft_memset((void *)&n_frac, 0, sizeof(t_newton_fractal));
	if (ft_strlen(av[1]) == 6 && \
		!ft_strncmp(av[1], "newton", ft_strlen(av[1])))
	{
		if (newton_parsing(ac, av, &n_frac))
			return (1);
		app->type = 0;
	}
	else
	{
		if (non_newton_parsing(ac, av, &fractal))
			return (1);
		app->type = 1;
	}
	app_init(app, fractal, n_frac);
	return (0);
}
