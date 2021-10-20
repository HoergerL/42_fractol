NAME = fractol
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBXFLAGS = -O3 -framework OpenGL -framework AppKit -Wall -Wextra -Lminilibx -lmlx
FILES = fractol.c calculate_fractols.c hooks.c handle_input_utils.c handle_input.c hooks_utils.c

all: $(NAME)
$(NAME):
	make -C ./minilibx
	$(CC) $(CFLAGS) $(LIBXFLAGS) $(FILES) -o $(NAME)

clean:
	cd minilibx && make clean
fclean: clean
	rm -f $(NAME)
re: fclean all
bonus: all