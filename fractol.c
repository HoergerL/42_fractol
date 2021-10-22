/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:18:23 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/22 14:34:09 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	ft_colourcalc(t_vars *vars)
{
	double	ratio;
	int		colour[4];

	ratio = (double) vars->iteration / (double) vars->max_it;
	colour[0] = 0;
	colour[(0 + vars->shift) % 3 + 1]
		= (9 * (1 - ratio) * (1 - ratio) * (1 - ratio)
			* (1 - ratio) * ratio * 255);
	colour[(1 + vars->shift) % 3 + 1]
		= (15 * (1 - ratio) * (1 - ratio) * ratio * ratio * 255);
	colour[(2 + vars->shift) % 3 + 1]
		= (9 * (1 - ratio) * ratio * ratio * ratio * ratio * 255);
	return (create_trgb(0, colour[1], colour[2], colour[3]));
}

void	create_pixel(t_vars *vars)
{
	double	percentage_y;
	double	percentage_x;

	while (vars->x < vars->window_x)
	{
		while (vars->y < vars->window_y)
		{
			percentage_x = vars->x / vars->window_x;
			percentage_y = vars->y / vars->window_y;
			if (vars->mode == JULIA)
				calculate_julia(vars, percentage_x, percentage_y);
			else if (vars->mode == MANDELBROT_MOD)
				calculate_mandelbrot_mod(vars, percentage_x, percentage_y);
			else
				calculate_mandelbrot(vars, percentage_x, percentage_y);
			my_mlx_pixel_put(vars->data, vars->x, vars->y, ft_colourcalc(vars));
			vars->y = vars->y + 1;
		}
		vars->y = 0;
		vars->x = vars->x + 1;
	}
}

void	create_Fractal(t_vars *vars)
{
	t_data	img;

	vars->iteration = 0;
	vars->x = 0.0;
	vars->y = 0.0;
	vars->data = &img;
	vars->data->img = mlx_new_image(vars->window->mlx,
			vars->window_x, vars->window_y);
	vars->data->addr = mlx_get_data_addr(vars->data->img,
			&vars->data->bits_per_pixel, &vars->data->line_length,
			&vars->data->endian);
	create_pixel(vars);
	mlx_put_image_to_window(vars->window->mlx, vars->window->win,
		vars->data->img, 0, 0);
	mlx_mouse_hook(vars->window->win, mouse_hook, vars);
	mlx_key_hook(vars->window->win, key_hook, vars);
	mlx_hook(vars->window->win, 17, 0, exit_hook, vars);
	mlx_loop(vars->window->mlx);
}

int	main(int argc, char *argv[])
{
	t_window	window;
	t_vars		vars;

	vars.range_R = 3.5;
	vars.range_I = 2;
	vars.middle_I = 0;
	vars.shift = 0;
	vars.middle_x = 500.0;
	vars.window_x = 1000;
	vars.window_y = 500;
	vars.middle_R = -0.75;
	vars.max_it = 100;
	vars.middle_y = 250.0;
	vars.initial_z_I = 0.0;
	vars.initial_z_R = 0.0;
	vars.initial_c_I = 0.5;
	vars.initial_c_R = 0.3;
	handle_input(argc, argv, &vars);
	vars.window = &window;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx,
			vars.window_x, vars.window_y, "Fractal");
	create_Fractal(&vars);
	return (0);
}
