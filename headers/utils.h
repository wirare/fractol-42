/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:58:06 by ellanglo          #+#    #+#             */
/*   Updated: 2025/02/11 15:49:25 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
int		ref_atof(const char *str, double *nb);
int		ref_atoi(const char *nptr, int *nb);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		power(int nb, unsigned int pow);
#endif
