/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:04:27 by ellanglo          #+#    #+#             */
/*   Updated: 2024/12/14 23:17:05 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*start;

	start = s;
	while (n)
	{
		*(unsigned char *)s = c;
		s++;
		n--;
	}
	return (start);
}
