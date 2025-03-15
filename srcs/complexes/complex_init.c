/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:51:02 by ellanglo          #+#    #+#             */
/*   Updated: 2025/03/11 18:03:46 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "complex_number.h"

__attribute__((always_inline))
inline void	z_init(double re, double im, t_complex *z)
{
	z->re = re;
	z->im = im;
}
