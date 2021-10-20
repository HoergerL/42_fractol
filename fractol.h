/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:16:34 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/20 13:08:45 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

# define JULIA 1
# define MANDELBROT 2
# define MANDELBROT_MOD 3
# define KEY_1	18
# define KEY_2	19
# define KEY_3	20
# define KEY_W	13
# define KEY_S	1
# define KEY_UP	126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_ESC	53
# define KEY_C	8

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_window {
	void	*mlx;
	void	*win;
}				t_window;

typedef struct s_vars {
	double		window_x;
	double		window_y;
	t_window	*window;
	double		range_R;
	double		range_I;
	double		middle_R;
	double		middle_I;
	int			max_it;
	double		middle_x;
	double		middle_y;
	double		x;
	double		y;
	t_data		*data;
	double		z_R;
	double		z_I;
	double		initial_z_R;
	double		initial_z_I;
	double		temp_z_R;
	double		c_R;
	double		c_I;
	double		initial_c_R;
	double		initial_c_I;
	int			iteration;
	int			mode;
	int			shift;
}				t_vars;

void	create_Fractal(t_vars *vars);
void	calculate_mandelbrot(t_vars *vars, double perc_x, double perc_y);
void	calculate_mandelbrot_mod(t_vars *vars, double perc_x, double perc_y);
void	calculate_julia(t_vars *vars, double perc_x, double perc_y);
int		exit_hook(t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
void	handler_fractol_change(int keycode, t_vars *vars);
void	handler_arrows(int keycode, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	handle_input(int argc, char *argv[], t_vars *vars);
void	set_vars_mandelbrot(t_vars *vars);
void	set_vars_mandelbrot_mod(t_vars *vars);
void	set_vars_julia(t_vars *vars);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_strlen(const char *s);
int		ft_strchr(const char *s, int c);
void	print_error(void);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_isdigit(int c);
int		ft_strlen(const char *s);
int		ft_strchr(const char *s, int c);
int		exit_hook(t_vars *vars);
void	mouse_hook_util(int flag, int x, int y, t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
void	set_vars_julia(t_vars *vars);
int		create_trgb(int t, int r, int g, int b);
#endif