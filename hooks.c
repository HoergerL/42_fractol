/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:27:55 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/20 13:06:06 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_vars_mandelbrot(t_vars *vars)
{
	vars->range_R = 3.5;
	vars->range_I = 2;
	vars->middle_I = 0;
	vars->middle_R = -0.75;
	vars->initial_z_I = 0.0;
	vars->initial_z_R = 0.0;
	vars->mode = MANDELBROT;
}

void	set_vars_mandelbrot_mod(t_vars *vars)
{
	vars->initial_z_I = 0.0;
	vars->initial_z_R = 0.0;
	vars->range_R = 3.5;
	vars->range_I = 2.5;
	vars->middle_I = 0;
	vars->middle_R = 0;
	vars->mode = MANDELBROT_MOD;
}

void	handler_fractol_change(int keycode, t_vars *vars)
{
	if (keycode == KEY_1)
		set_vars_julia(vars);
	else if (keycode == KEY_2)
		set_vars_mandelbrot(vars);
	else if (keycode == KEY_3)
		set_vars_mandelbrot_mod(vars);
	if (keycode == KEY_1 || keycode == KEY_3 || keycode == KEY_2)
		create_Fractal(vars);
}

void	handler_arrows(int keycode, t_vars *vars)
{
	if (keycode == KEY_UP)
	{
		vars->middle_I = vars->middle_I - 0.1 * vars->range_I;
		create_Fractal(vars);
	}
	else if (keycode == KEY_DOWN)
	{
		vars->middle_I = vars->middle_I + 0.1 * vars->range_I;
		create_Fractal(vars);
	}
	else if (keycode == KEY_LEFT)
	{
		vars->middle_R = vars->middle_R - 0.1 * vars->range_R;
		create_Fractal(vars);
	}
	else if (keycode == KEY_RIGHT)
	{
		vars->middle_R = vars->middle_R + 0.1 * vars->range_R;
		create_Fractal(vars);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
	{
		vars->max_it = vars->max_it / 0.9 + 1;
		create_Fractal(vars);
	}
	else if (keycode == KEY_S)
	{
		if ((vars->max_it * 0.9 + 1) < 2)
			vars->max_it = 1;
		else
			vars->max_it = vars->max_it * 0.9;
		create_Fractal(vars);
	}
	else if (keycode == KEY_ESC)
		exit_hook(vars);
	if (keycode == KEY_C)
	{
		vars->shift = vars->shift + 1;
		create_Fractal(vars);
	}
	handler_arrows(keycode, vars);
	handler_fractol_change(keycode, vars);
	return (0);
}
