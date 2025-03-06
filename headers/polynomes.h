/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:22:07 by ellanglo          #+#    #+#             */
/*   Updated: 2025/02/11 16:13:00 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef POLYNOMES_H
# define POLYNOMES_H

# include "complex_number.h"
# include <stdint.h>

typedef struct s_app	t_app;

typedef struct s_polynomeN
{
	int		degree;
	float	*coef;
}	t_polynomeN;

typedef struct s_polynomeN_info
{
	t_polynomeN	polynomes;
	t_polynomeN	derivative;
	t_complex	*root;
	uint8_t		flag;
}	t_polynomeN_info;

int					derivative_calc(t_polynomeN_info *polynomes);
void				find_cubic_root(t_polynomeN_info *polynomes);
void				free_poly(t_polynomeN_info *polynome);
double				calc_delta(double q, double p);
double				calc_p(t_polynomeN poly);
double				calc_q(t_polynomeN poly);
double				calc_u(double delta, double q);
double				calc_v(double delta, double q);
t_polynomeN			init_poly_n(double *coef, int degree);
t_polynomeN_info	init_poly_n_info(t_polynomeN polynome);

#endif
