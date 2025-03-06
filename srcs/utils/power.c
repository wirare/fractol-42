/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:26:43 by ellanglo          #+#    #+#             */
/*   Updated: 2024/12/14 23:17:12 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

int	power(int nb, unsigned int pow)
{
	int	result;

	result = 1;
	while (pow--)
		result *= nb;
	return (result);
}
