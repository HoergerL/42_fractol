#include "minilibx/mlx.h"
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook: %i, %s!\n", keycode, vars);
}

int mouse_hook(int button, int x,int y, void *param)
{
	printf("x: %i, y: %i, button: %i\n", x, y, button);
	//scroll out = button 4
	//scroll in = button 5
}
int	main(void)
{
	t_vars	vars;
	int x = 0;
	int y = 0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	//mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	//mlx_mouse_get_pos(vars.win, x, y);
	mlx_loop(vars.mlx);
	return 0;
}