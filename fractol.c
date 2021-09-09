#include "minilibx/mlx.h"

	double range_R;
	double range_I;
	double middle_R = -0.75;
	double middle_I = 0;
	int max_iterations = 100;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;
void create_Mandelbrot(double window_x, double window_y, t_vars *vars);
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

int find_middle_Pixel(int window_x, int window_y, t_data *data)
{
	int middle_x = window_x / 2;
	int middle_y = window_y / 2;
	//my_mlx_pixel_put(data->img, middle_x, middle_y, 0x00000000);
}

int mouse_hook(int button, int x,int y, t_vars *vars)
{
	double middle_x = 1000 / 2;
	double  middle_y = 500 / 2;
	printf("x: %i, y: %i, button: %i\n", x, y, button);
	if (button == 4) // zoom in
	{
		
		printf("middle_R = %f, middle_I= %f\n", middle_R, middle_I);
		range_I = range_I * 0.8;
		range_R = range_R * 0.8;
		middle_R = middle_R + ((x - middle_x) / 1000) * range_R * 0.2;
		middle_I = middle_I + ((y - middle_y) / 500 ) * range_I * 0.2;
		create_Mandelbrot(1000, 500, vars);
		
	}
	else if (button == 5) // zoom out
	{
		
		range_I = range_I / 0.8;
		range_R = range_R / 0.8;
		create_Mandelbrot(1000, 500, vars);
		
	}
	//scroll out = button 4
	//scroll in = button 5
	//up = 126
	//down = 125
}


int key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook: %i!\n", keycode);
	if (keycode == 0) // a
	{
		middle_R = middle_R - 0.1 * range_R;
		create_Mandelbrot(1000, 500, vars);
	}
	else if (keycode == 13) // w
	{
		middle_I = middle_I - 0.1 * range_I;
		create_Mandelbrot(1000, 500, vars);
	}
	else if (keycode == 2) // d
	{
		middle_R = middle_R + 0.1 * range_R;
		create_Mandelbrot(1000, 500, vars);
	}
	else if (keycode == 1) // s
	{
		middle_I = middle_I + 0.1 * range_I;
		create_Mandelbrot(1000, 500, vars);
	}
	else if (keycode == 126) // zoom in
	{
		max_iterations =  max_iterations / 0.9 + 1;
		printf("max iteration: %i", max_iterations);
		create_Mandelbrot(1000, 500, vars);
	}
	else if (keycode == 125) // zoom out
	{
		printf("max iteration: %i", max_iterations);
		if ((max_iterations = max_iterations * 0.9 + 1) < 2)
			max_iterations = 1;
		else
		max_iterations = max_iterations * 0.9;
		create_Mandelbrot(1000, 500, vars);
	}
	return 0;
}



void create_Mandelbrot(double window_x, double window_y, t_vars	*vars)
{
	//void	*mlx;
	//void	*mlx_win;
	t_data	img;
	
	double x;
	double y;
	double percentage_y;
	double percentage_x;
	//int max_iterations;
	//double middle_R;
	//double middle_I;

	double c_R;
	double c_I;
	int iteration;
	double z_R;
	double z_I;
	double temp_z_R;

	//max_iterations = 100;

	iteration = 0;
	z_R = 0;
	z_I = 0;
	x = 0.0;
	y = 0.0;

	
	img.img = mlx_new_image(vars->mlx, window_x, window_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (x < window_x)
	{
		while (y < window_y)
		{
			percentage_x = x / window_x;
			percentage_y = y / window_y;
			c_R = percentage_x * range_R + middle_R - range_R / 2;
			c_I = percentage_y * range_I + middle_I - range_I / 2;
			iteration = 0;
			z_I = 0;
			z_R = 0;

			while (iteration < max_iterations && z_R * z_R + z_I * z_I <= 4.0)
			{
				temp_z_R = z_R * z_R - z_I * z_I + c_R;
				z_I = 2 * z_R * z_I + c_I;
				z_R = temp_z_R;
				iteration++;
			}
		
		
			if (iteration >= max_iterations - 1)
			{
				//printf("Pixel: %f/%f, Farbe Schwarz\n", x, y);
				my_mlx_pixel_put(&img, x, y, create_trgb(0, 100 * iteration / max_iterations, 200, 255 * iteration / max_iterations));
			}
			else if (iteration >= max_iterations / 2)
			{
				//printf("Pixel: %f/%f, Farbe Schwarz\n", x, y);
				my_mlx_pixel_put(&img, x, y, create_trgb(0, 100, 255 * iteration / max_iterations, 100));
			}
			else
			{
				//printf("Pixel: %f/%f, Farbe weiss\n", x, y);
				my_mlx_pixel_put(&img, x, y, create_trgb(0, 100, 100, 255 * iteration / max_iterations));
			}
			y++;
		}
		y = 0;
		x++;
		
	}
	find_middle_Pixel(window_x, window_y, &img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop(vars->mlx);
}

int main()
{
		range_R = 3.5;
	range_I = 2;
	t_vars	vars;
	double window_x;
	double window_y;
	window_x = 1000;
	window_y = 500;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, window_x, window_y, "Hello world!");
	create_Mandelbrot(window_x, window_y, &vars);
}

