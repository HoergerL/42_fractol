/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:16:34 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/22 14:46:35 by lhoerger         ###   ########.fr       */
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



//******************** calculate_fractols.h *********************************//

// this function does the actual math to create the Mandelbrot fractal
void	calculate_mandelbrot(t_vars *vars, double perc_x, double perc_y);
// this function does the actual math to create the tricorn fractal
void	calculate_mandelbrot_mod(t_vars *vars, double perc_x, double perc_y);
// this function does the actual math to create the Julia fractal
void	calculate_julia(t_vars *vars, double perc_x, double perc_y);
// saves a colour in an integer
int		create_trgb(int t, int r, int g, int b);


//******************** fractol.c ********************************************//

// this function manages the creation of fractals
void	create_Fractal(t_vars *vars);
// this function is responsible for the calculations behind one single pixel
void	create_pixel(t_vars *vars);
// this function calculates the different colors depending on the shift variable
int		ft_colourcalc(t_vars *vars);
//with this function you put the pixel at the right place of the window
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);


//******************** handle_input_utils.c *********************************//

// this function is called when an error with the input occurs
void	print_error(void);
// this function searches char c in string s and returns the index
int		ft_strchr(const char *s, int c);
// this function compares 2 strings and returns the difference of the first different chars
int		ft_strncmp(char *s1, char *s2, unsigned int n);
// this function checks whether c is digit
int		ft_isdigit(int c);
//this function calculates the length of a string
int		ft_strlen(const char *s);


//******************** handle_input.c ***************************************//
// this function coordinates the handling of the input char
void	handle_input(int argc, char *argv[], t_vars *vars);
// this function handles the input for the Julia set
void	check_julia(int argc, t_vars *vars, char *argv[]);
// this function converts a String to a double
double	ft_atof(char *str);
//this function does the convertion of the non decimal places
void	ft_atof_helper(char *str, int *i, double *num);
// this function calculates the power of a number
int	power(int num, int pow);


//******************** hooks_utils.c ***************************************//
// this function handles the exit of the window (ESC and red cross)
int		exit_hook(t_vars *vars);
// this function handles the mouse hook for zooming in and out
void	mouse_hook_util(int flag, int x, int y, t_vars *vars);
// this function coordinates the mouse hook for zooming in and out
int		mouse_hook(int button, int x, int y, t_vars *vars);
// this function sets the variables in case a Julia set should be drawn
void	set_vars_julia(t_vars *vars);


//******************** hooks.c **********************************************//
// this function handles the change of the displayed fractal by pressing 1 2 or 3
void	handler_fractol_change(int keycode, t_vars *vars);
// this function handles the pressing of arrows to move the frame
void	handler_arrows(int keycode, t_vars *vars);
// this function coordinates the handling of key press events
int		key_hook(int keycode, t_vars *vars);
// this function sets the variables for the creation of mandelbrot
void	set_vars_mandelbrot(t_vars *vars);
// this function sets the variables for the creation of tricorn
void	set_vars_mandelbrot_mod(t_vars *vars);

#endif