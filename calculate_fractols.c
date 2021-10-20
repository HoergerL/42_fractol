/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractols.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:32:54 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/20 12:40:42 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_mandelbrot(t_vars *vars, double perc_x, double perc_y)
{
	vars->c_R = perc_x * vars->range_R + vars->middle_R - vars->range_R / 2;
	vars->c_I = perc_y * vars->range_I + vars->middle_I - vars->range_I / 2;
	vars->iteration = 0;
	vars->z_I = vars->initial_z_I;
	vars->z_R = vars->initial_z_R;
	while (vars->iteration < vars->max_it && vars->z_R * vars->z_R
		+ vars->z_I * vars->z_I <= 4.0)
	{
		vars->temp_z_R = vars->z_R * vars->z_R - vars->z_I
			* vars->z_I + vars->c_R;
		vars->z_I = 2 * vars->z_R * vars->z_I + vars->c_I;
		vars->z_R = vars->temp_z_R;
		vars->iteration = vars->iteration + 1;
	}
}

void	calculate_mandelbrot_mod(t_vars *vars, double perc_x, double perc_y)
{
	vars->c_R = perc_x * vars->range_R + vars->middle_R - vars->range_R / 2;
	vars->c_I = perc_y * vars->range_I + vars->middle_I - vars->range_I / 2;
	vars->iteration = 0;
	vars->z_I = vars->initial_z_I;
	vars->z_R = vars->initial_z_R;
	while (vars->iteration < vars->max_it && vars->z_R * vars->z_R
		+ vars->z_I * vars->z_I <= 4.0)
	{
		vars->temp_z_R = vars->z_R * vars->z_R - vars->z_I
			* vars->z_I + vars->c_R;
		vars->z_I = -2 * vars->z_R * vars->z_I + vars->c_I;
		vars->z_R = vars->temp_z_R;
		vars->iteration = vars->iteration + 1;
	}
}

void	calculate_julia(t_vars *vars, double perc_x, double perc_y)
{
	vars->z_R = perc_x * vars->range_R + vars->middle_R - vars->range_R / 2;
	vars->z_I = perc_y * vars->range_I + vars->middle_I - vars->range_I / 2;
	vars->iteration = 0;
	vars->c_I = vars->initial_c_I;
	vars->c_R = vars->initial_c_R;
	while (vars->iteration < vars->max_it && vars->z_R * vars->z_R
		+ vars->z_I * vars->z_I <= 4.0)
	{
		vars->temp_z_R = vars->z_R * vars->z_R - vars->z_I
			* vars->z_I + vars->c_R;
		vars->z_I = 2 * vars->z_R * vars->z_I + vars->c_I;
		vars->z_R = vars->temp_z_R;
		vars->iteration = vars->iteration + 1;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
