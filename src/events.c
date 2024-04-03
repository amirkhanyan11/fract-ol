#include "fractol.h"

#define GL_ESCAPE 53
#define GL_ARROWLEFT 123
#define GL_ARROWRIGHT 124
#define GL_ARROWUP 126
#define GL_ARROWDOWN 125
#define GL_PLUS 69
#define GL_MINUS 78

#define GL_MOUSEWHEELUP 5
#define GL_MOUSEWHEELDOWN 4


int key_handle(int keycode, t_fractal * fractal)
{
	if (GL_ESCAPE == keycode)
		destroy_handle(fractal);

	else if (GL_ARROWLEFT == keycode)
		fractal->shift_x -= (0.5 / fractal->zoom);

	else if (GL_ARROWRIGHT == keycode)
		fractal->shift_x += (0.5 / fractal->zoom);

	else if (GL_ARROWUP == keycode)
		fractal->shift_y += (0.5 / fractal->zoom);

	else if (GL_ARROWDOWN == keycode)
		fractal->shift_y -= (0.5 / fractal->zoom);

	else if (GL_PLUS == keycode)
		fractal->resolution += 25;

	else if (GL_MINUS == keycode)
		fractal->resolution -= 25;

	fractal_render(fractal);
	// printf("%d\n", keycode);

	return 0;
}


int	destroy_handle(t_fractal *fractal)
{
	mlx_destroy_window(fractal->connect.mlx, fractal->connect.win);
	exit (EXIT_SUCCESS); // exit(0);
}


int mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	if (GL_MOUSEWHEELDOWN == button)
		fractal->zoom *= 0.7;
	else if (GL_MOUSEWHEELUP == button)
		fractal->zoom *= 1.3;
	fractal_render(fractal);
	// printf("%d\n", button);

	return 0;
}

// int (*f)(int x, int y, void *param)

int julia_handle(int x, int y, t_fractal * fractal)
{
	fractal->julia.real = (__rescale(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	fractal->julia.i = (__rescale(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	fractal_render(fractal);
	return 0;
}


void event_handle(t_fractal * fractal)
{
	mlx_hook(fractal->connect.win, ON_KEYDOWN, DUMMY, key_handle, fractal); // keys
	mlx_hook(fractal->connect.win, ON_MOUSEDOWN, DUMMY, mouse_handle, fractal); // mouse
	mlx_hook(fractal->connect.win, ON_DESTROY, DUMMY, destroy_handle, fractal); // uuuf esim

	if (!ft_strncmp(fractal->name, "julia", ft_strlen("julia")))
	{
		mlx_hook(fractal->connect.win, ON_MOUSEMOVE, DUMMY, julia_handle, fractal);
	}
}
