
mandelbrot:
	gcc fractol.c -framework OpenGL -framework AppKit -Wall -Wextra -Lminilibx -lmlx
hook:
	gcc hook.c -framework OpenGL -framework AppKit -Wall -Wextra -Lminilibx -lmlx
window :
	gcc creating_window.c -framework OpenGL -framework AppKit -Wall -Wextra -Lminilibx -lmlx