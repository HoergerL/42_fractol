#include "minilibx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_window {
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
	int			max_iterations;
	double		middle_x;
	double		middle_y;
	double		x;
	double		y;
	t_data		*data;
	double		z_R;
	double		z_I;
	double		temp_z_R;
	double		c_R;
	double		c_I;
	int			iteration;
}				t_vars;

void create_Fractal(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	exit_hook(void)
{
	//mlx_destroy_image
	//mlx_destroy_window
	exit(0);
}
int mouse_hook(int button, int x,int y, t_vars *vars)
{
	printf("x: %i, y: %i, button: %i\n", x, y, button);
	if (button == 4) //zoom in
	{
		double ratio_x = (x - vars->middle_x) / 1000;
		double ratio_y = (y - vars->middle_y) / 500;
		vars->middle_R = vars->middle_R + (vars->range_R * ratio_x);
		printf("middle_R = %f, ratio =  %f\n", vars->middle_R, ratio_x);
		vars->middle_I = vars->middle_I + (vars->range_I * ratio_y);
		printf("middle_I = %f, ratio =  %f\n", vars->middle_I, ratio_y);
		//middle_x = x - middle_x;
		vars->range_R = vars->range_R * 0.8;
		vars->range_I = vars->range_I * 0.8;

		vars->middle_R = vars->middle_R - (vars->range_R * ratio_x);
		vars->middle_I = vars->middle_I - (vars->range_I * ratio_y);
		create_Fractal(vars);

	}
	else if (button == 5) // zoom out
	{
		
		vars->range_I = vars->range_I / 0.8;
		vars->range_R = vars->range_R / 0.8;
		create_Fractal(vars);
		
	}
}
int key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook: %i!\n", keycode);

	if (keycode == 13) // w
	{
		vars->max_iterations =  vars->max_iterations / 0.9 + 1;
		//printf("max iteration: %i", max_iterations);
		create_Fractal(vars);
	}
	else if (keycode == 1) // s
	{
		//printf("max iteration: %i", max_iterations);
		if ((vars->max_iterations = vars->max_iterations * 0.9 + 1) < 2)
			vars->max_iterations = 1;
		else
		vars->max_iterations = vars->max_iterations * 0.9;
		create_Fractal(vars);
	}
	else if (keycode == 126) // improve max_iteration
	{
		vars->middle_I = vars->middle_I - 0.1 * vars->range_I;
		create_Fractal(vars);
	}
	else if (keycode == 125) // lower max_iteration
	{
		vars->middle_I = vars->middle_I + 0.1 * vars->range_I;
		create_Fractal(vars);
	}
	else if (keycode == 123)
	{
		vars->middle_R = vars->middle_R - 0.1 * vars->range_R;
		create_Fractal(vars);
	}
	else if (keycode == 124)
	{
		vars->middle_R = vars->middle_R + 0.1 * vars->range_R;
		create_Fractal(vars);
	}
	else if (keycode == 53)
	{
		exit (0);
	}
	{
		/* code */
	}
	
	return 0;
}

void create_colors(t_vars *vars)
{
	if (vars->iteration >= vars->max_iterations - 1)
			{
				//printf("Pixel: %f/%f, Farbe Schwarz\n", x, y);
				my_mlx_pixel_put(vars->data, vars->x, vars->y, create_trgb(0, 100 * vars->iteration / vars->max_iterations, 200, 255 * vars->iteration / vars->max_iterations));
			}
			else if (vars->iteration >= vars->max_iterations / 2)
			{
				//printf("Pixel: %f/%f, Farbe Schwarz\n", x, y);
				my_mlx_pixel_put(vars->data, vars->x, vars->y, create_trgb(0, 100, 255 * vars->iteration / vars->max_iterations, 100));
			}
			else
			{
				//printf("Pixel: %f/%f, Farbe weiss\n", x, y);
				my_mlx_pixel_put(vars->data, vars->x, vars->y, create_trgb(0, 100, 100, 255 * vars->iteration / vars->max_iterations));
			}
			if (vars->iteration % 2 ==0)
			{
				my_mlx_pixel_put(vars->data, vars->x, vars->y, create_trgb(0,255, 0, 0));
			}
			else if (vars->iteration % 2 == 1)
			{
				my_mlx_pixel_put(vars->data, vars->x, vars->y, create_trgb(0,0, 255, 0));
			}
}
void calculate_mandelbrot(t_vars *vars, double percentage_x, double percentage_y)
{
	vars->c_R = percentage_x * vars->range_R + vars->middle_R - vars->range_R / 2;
	vars->c_I = percentage_y * vars->range_I + vars->middle_I - vars->range_I / 2;
	vars->iteration = 0;
	vars->z_I = 0.0;
	vars->z_R = 0.0;
	while (vars->iteration < vars->max_iterations && vars->z_R * vars->z_R + vars->z_I * vars->z_I <= 4.0)
	{
		vars->temp_z_R = vars->z_R * vars->z_R - vars->z_I * vars->z_I + vars->c_R;
		vars->z_I = 2 * vars->z_R * vars->z_I + vars->c_I;
		vars->z_R = vars->temp_z_R;
		vars->iteration = vars->iteration + 1;
	}
}

void calculate_julia(t_vars *vars, double percentage_x, double percentage_y)
{
	vars->z_R = percentage_x * vars->range_R + vars->middle_R - vars->range_R / 2;
	vars->z_I = percentage_y * vars->range_I + vars->middle_I - vars->range_I / 2;
	vars->iteration = 0;
	vars->c_I = 0.5;
	vars->c_R = 0.3;
	while (vars->iteration < vars->max_iterations && vars->z_R * vars->z_R + vars->z_I * vars->z_I <= 4.0)
	{
		vars->temp_z_R = vars->z_R * vars->z_R - vars->z_I * vars->z_I + vars->c_R;
		vars->z_I = 2 * vars->z_R * vars->z_I + vars->c_I;
		vars->z_R = vars->temp_z_R;
		vars->iteration = vars->iteration + 1;
	}
}

void create_pixel(t_vars *vars)
{
	double percentage_y;
	double percentage_x;

	while (vars->x < vars->window_x)
	{
		while (vars->y < vars->window_y)
		{
			percentage_x = vars->x / vars->window_x;
			percentage_y = vars->y / vars->window_y;

			//calculate_julia(vars, percentage_x, percentage_y);
			calculate_mandelbrot(vars, percentage_x, percentage_y);
			create_colors(vars);
			vars->y= vars->y + 1;
		}
		vars->y = 0;
		vars->x = vars->x + 1;
		
	}
}

void create_Fractal(t_vars *vars)
{
	t_data	img;
	
	vars->iteration = 0;
	vars->x = 0.0;
	vars->y = 0.0;
	vars->data = &img;
	vars->data->img = mlx_new_image(vars->window->mlx, vars->window_x, vars->window_y);
	vars->data->addr = mlx_get_data_addr(vars->data->img, &vars->data->bits_per_pixel, &vars->data->line_length,
								&vars->data->endian);
	create_pixel(vars);
	mlx_put_image_to_window(vars->window->mlx, vars->window->win, vars->data->img, 0, 0);
	mlx_mouse_hook(vars->window->win, mouse_hook, vars);
	mlx_key_hook(vars->window->win, key_hook, vars);
	mlx_hook(vars->window->win, 17, 0, exit_hook, &vars);
	mlx_loop(vars->window->mlx);
}

int main()
{
	t_window	window;
	t_vars		vars;

	vars.range_R = 3.5;
	vars.range_I = 2;
	vars.middle_I = 0;
	vars.middle_x = 500.0;
	vars.window_x = 1000;
	vars.window_y = 500;
	vars.middle_R = -0.75;
	vars.max_iterations = 100;
	vars.middle_y = 250.0;
	vars.window = &window;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, vars.window_x, vars.window_y, "Fractal");
	create_Fractal(&vars);
	system("leaks a.out");
	return 0;
}
