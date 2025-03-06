/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:29:00 by ellanglo          #+#    #+#             */
/*   Updated: 2024/12/14 23:16:59 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;

	s1_uc = (unsigned char *)s1;
	s2_uc = (unsigned char *)s2;
	if (!n--)
		return (0);
	while ((*s1_uc || s1_uc) && (*s2_uc || s2_uc) && *s1_uc == *s2_uc && n)
	{
		s1_uc++;
		s2_uc++;
		n--;
	}
	return (*s1_uc - *s2_uc);
}
