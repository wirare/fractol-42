/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 00:35:09 by ellanglo          #+#    #+#             */
/*   Updated: 2024/12/14 23:17:10 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n--)
		return (0);
	while (*s1 && *s2 && (unsigned char)*s1 == (unsigned char)*s2 && n)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
