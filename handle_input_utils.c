/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:29:21 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/20 13:14:18 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	cnt;
	unsigned char	*s1x;
	unsigned char	*s2x;

	s1x = (unsigned char *) s1;
	s2x = (unsigned char *) s2;
	cnt = 0;
	while ((s1x[cnt] != '\0' || s2x[cnt] != '\0') && cnt < n)
	{
		if (s1x[cnt] != s2x[cnt])
		{
			return (s1x[cnt] - s2x[cnt]);
		}
		cnt++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}

int	ft_strchr(const char *s, int c)
{
	int	cnt;
	int	len;

	len = ft_strlen(s);
	cnt = 0;
	while (cnt <= len)
	{
		if (s[cnt] == c)
			return (cnt);
		cnt++;
	}
	return (-1);
}

void	print_error(void)
{
	write(1, "Your input was incorrect, please try again with ", 49);
	write(1, "other input\n", 13);
	write (1, "please remember, that the best results are generated ", 61);
	write(1, "if the numbers are between -1 and 1.\n", 38);
	write(1, "The possible Fractals you can picture with this project ", 57);
	write(1, "are the following:\n", 20);
	write(1, "./fractal Mandelbrot\n", 22);
	write(1, "./fractal Mandelbrot_Mod\n", 26);
	write(1, "./fractal Julia x.x y.y\n", 25);
	exit(1);
}
