/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:30:21 by ellanglo          #+#    #+#             */
/*   Updated: 2024/12/14 23:17:07 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	while (*s != c && *s)
		s++;
	if (!*s && c)
		return (NULL);
	return ((char *)s);
}
