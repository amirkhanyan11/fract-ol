#include "fractol.h"


void fractal_init(char *name, t_complex *julia, t_fractal *fractal)
{
	fractal->name = name;
	fractal->resolution = 42;
	fractal->color = BLACK;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->zoom = 1;

	if (!ft_strncmp(fractal->name, "julia", ft_strlen("julia")))
	{
		fractal->julia.real = julia->real;
		fractal->julia.i = julia->i;
	}

	fractal->connect.mlx = mlx_init();
	fractal->connect.win = mlx_new_window(fractal->connect.mlx, WIDTH, HEIGHT, fractal->name);
	fractal->img.img_ptr = mlx_new_image(fractal->connect.mlx, WIDTH, HEIGHT);

	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
												&fractal->img.bpp,
												&fractal->img.line_len,
												&fractal->img.endian);

	event_handle(fractal);

}
