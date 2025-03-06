/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:13:21 by ellanglo          #+#    #+#             */
/*   Updated: 2025/02/11 16:58:35 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "app_handler.h"
#include <unistd.h>

void	print_error(void)
{
	write(2, "Here are the available parameters:\n", 36);
	write(2, "-mandelbrot: Displays the Mandelbrot set\n", 41);
	write(2, "-mouse: Uses the mouse position to display the corresponding \
Julia set\n", 72);
	write(2, "-julia [Re(c)] [Im(c)]: Displays the Julia set for the given \
complex number c\n", 79);
	write(2, "-bship: Displays the Burning Ship fractal\n", 42);
	write(2, "-newton [a] [b] [c] [d]: Newton fractal for a function of the \
form ax^3 + bx^2 + cx + d\n", 88);
}
