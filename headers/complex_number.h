/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_number.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:41:24 by ellanglo          #+#    #+#             */
/*   Updated: 2025/03/13 16:18:43 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef COMPLEX_NUMBER_H
# define COMPLEX_NUMBER_H

typedef struct s_complex
{
	double	re;
	double	im;
	double	mod;
}	t_complex;

void	z_add(t_complex *z1, t_complex z2);
void	z_power(t_complex *z, int power);
void	z_init(double re, double im, t_complex *z);
void	z_mult(t_complex *z1, t_complex z2);
void	z_divide(t_complex *z1, t_complex z2);
double	mod2(t_complex z);

#endif
