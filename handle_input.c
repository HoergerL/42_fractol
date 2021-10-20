/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:48:48 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/20 13:10:47 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	power(int num, int pow)
{
	int	res;

	res = 1;
	while (pow >= 1)
	{
		res = res * num;
		pow--;
	}
	return (res);
}

void	ft_atof_helper(char *str, int *i, double *num)
{
	while (str[*i] != '\0' && str[*i] != '.')
	{
		if ((ft_strchr("+-0123456789", str[*i]) == -1))
			print_error();
		if (str[*i] == '+' || str[*i] == '-')
		{
			if (!str[*i + 1] || !ft_isdigit(str[*i + 1]))
				print_error();
		}
		*num = *num * 10 + str[*i] - '0';
		*i = *i + 1;
	}
}

double	ft_atof(char *str)
{
	double	num;
	int		i;
	int		decimal_place;

	num = 0;
	i = 0;
	decimal_place = 1;
	if (str[i] == '\0')
		return (num);
	ft_atof_helper(str, &i, &num);
	i++;
	if (num > INT_MAX || num < INT_MIN)
		print_error();
	while (str[i] != '\0' && decimal_place <= 16)
	{
		if ((ft_strchr("0123456789", str[i]) == -1))
			print_error();
		num = num + (double)(str[i] - '0') / power(10, decimal_place);
		i++;
		decimal_place++;
	}
	return (num);
}

void	check_julia(int argc, t_vars *vars, char *argv[])
{
	if (argc == 4)
	{
		set_vars_julia(vars);
		vars->initial_c_I = ft_atof(argv[2]);
		vars->initial_c_R = ft_atof(argv[3]);
	}
	else
		print_error();
}

void	handle_input(int argc, char *argv[], t_vars *vars)
{
	if (argc != 4 && argc != 2)
		print_error();
	if (ft_strncmp(argv[1], "Julia", ft_strlen(argv[1]) + 1) == 0)
		check_julia(argc, vars, argv);
	else if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1]) + 1) == 0)
	{
		if (argc == 2)
			set_vars_mandelbrot(vars);
		else
			print_error();
	}
	else if (ft_strncmp(argv[1], "Mandelbrot_Mod", ft_strlen(argv[1]) + 1) == 0)
	{
		if (argc == 2)
			 set_vars_mandelbrot_mod(vars);
		else
			print_error();
	}
	else
		print_error();
}
