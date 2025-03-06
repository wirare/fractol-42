/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:51:02 by ellanglo          #+#    #+#             */
/*   Updated: 2024/12/14 23:16:24 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "complex_number.h"

__attribute__((const))
t_complex	z_init(double re, double im)
{
	t_complex	z;

	z.re = re;
	z.im = im;
	return (z);
}
