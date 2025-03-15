/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_handler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:02:08 by ellanglo          #+#    #+#             */
/*   Updated: 2025/03/15 10:28:14 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef APP_HANDLER_H
# define APP_HANDLER_H

# include <stdint.h>
# include "complex_number.h"
# include "polynomes.h"

# define HEIGHT 1080
# define LENGTH 1920
# define NAME "Fract-0l"
# define FPS 120

typedef struct s_app	t_app;

typedef struct s_fractal
{
	void			(*__draw_fuction)(t_app *, t_complex, t_complex);
	t_complex		c;
	uint16_t		iteration;
	uint8_t			p_f;
	uint8_t			mode;
	int8_t			c_offset_mode;
	uint16_t		c_offset;
	uint8_t			mouse_flag;
	double			zoom_level;
	t_complex		zoom_offset;
	int				color_table;
}	t_fractal;

typedef struct s_newton_fractal
{
	uint16_t			iteration;
	uint8_t				p_f;
	double				zoom_level;
	t_complex			zoom_offset;
	t_polynomeN_info	polynome;
}	t_newton_fractal;

typedef struct s_app
{
	void				*mlx;
	void				*win;
	void				*img;
	t_fractal			env;
	t_newton_fractal	n_env;
	uint8_t				type;
	const char			*name;
}	t_app;

void	app_init(t_app *app, t_fractal env, t_newton_fractal n_env);
void	app_destroy(t_app *app, int code);
int		__on_update(void *app);
int		parse_input(int ac, char **av, t_app *app);
int		init_julia(int ac, char **av, t_fractal *fractal);
void	init_fractal(t_fractal *fractal);
void	init_newton(t_newton_fractal *fractal);
int		set_poly(t_newton_fractal *fractal, double *poly);
void	print_error(void);
//=========EVENT=========
void	event_handler(t_app *app);
int		key_hook(int key, void *app);
int		n_key_hook(int key, void *app);
int		window_hook(int event, void *mlx);
int		wheel_hook(int action, void *app);
int		mouse_hook(int action, void *app);
int		n_wheel_hook(int action, void *app);
#endif
