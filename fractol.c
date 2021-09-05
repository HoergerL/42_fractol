#include "minilibx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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

void create_Mandelbrot(double window_x, double window_y)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int i = 100;
	int j = 100;

	
	double x;
	double y;
	double percentage_y;
	double percentage_x;
	int max_iterations;
	double middle_R;
	double middle_I;
	double range_R;
	double range_I;
	double c_R;
	double c_I;
	int iteration;
	double z_R;
	double z_I;
	double temp_z_R;
	double colorvalue;

	max_iterations = 100;
	middle_R = -0.75;
	middle_I = 0;
	range_R = 3.5;
	range_I = 2;
	iteration = 0;
	z_R = 0;
	z_I = 0;
	x = 0.0;
	y = 0.0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, window_x, window_y, "Hello world!");
	img.img = mlx_new_image(mlx, window_x, window_y);
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
				my_mlx_pixel_put(&img, x, y, create_trgb(125, 255, 100, 100));
			}
			else if (iteration >= max_iterations / 2)
			{
				//printf("Pixel: %f/%f, Farbe Schwarz\n", x, y);
				my_mlx_pixel_put(&img, x, y, create_trgb(0, 100, 255, 100));
			}
			else
			{
				//printf("Pixel: %f/%f, Farbe weiss\n", x, y);
				my_mlx_pixel_put(&img, x, y, create_trgb(0, 100, 100, 255));
			}
			y++;
		}
		y = 0;
		x++;
		
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

int main()
{
	double window_x;
	double window_y;
	window_x = 1500;
	window_y = 1000;
	create_Mandelbrot(window_x, window_y);
}

