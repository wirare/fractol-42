/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:08:51 by ellanglo          #+#    #+#             */
/*   Updated: 2024/11/28 15:14:27 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef NORMALIZE_H
# define NORMALIZE_H

# define LENGTH 1920
# define HEIGHT 1080

double	normalize_x(double pos_x, double z_l);
double	normalize_y(double pos_y, double z_l);
#endif
