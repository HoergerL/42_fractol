/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:52:04 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/20 12:52:14 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_hook(t_vars *vars)
{
	mlx_destroy_image(vars->window->mlx, vars->data->img);
	mlx_destroy_window(vars->window->mlx, vars->window->win);
	exit(0);
}

void	mouse_hook_util(int flag, int x, int y, t_vars *vars)
{
	double	ratio_x;
	double	ratio_y;

	ratio_x = (x - vars->middle_x) / 1000;
	ratio_y = (y - vars->middle_y) / 500;
	vars->middle_R = vars->middle_R + (vars->range_R * ratio_x);
	vars->middle_I = vars->middle_I + (vars->range_I * ratio_y);
	if (flag == 1)
	{
		vars->range_R = vars->range_R * 0.8;
		vars->range_I = vars->range_I * 0.8;
	}
	else
	{
		vars->range_R = vars->range_R / 0.8;
		vars->range_I = vars->range_I / 0.8;
	}
	vars->middle_R = vars->middle_R - (vars->range_R * ratio_x);
	vars->middle_I = vars->middle_I - (vars->range_I * ratio_y);
	create_Fractal(vars);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
		mouse_hook_util(1, x, y, vars);
	else if (button == 5)
		mouse_hook_util(2, x, y, vars);
	return (0);
}

void	set_vars_julia(t_vars *vars)
{
	vars->mode = JULIA;
	vars->initial_c_I = 0.5;
	vars->initial_c_R = 0.3;
	vars->range_R = 3.5;
	vars->range_I = 2.5;
	vars->middle_I = 0;
	vars->middle_R = 0;
}
