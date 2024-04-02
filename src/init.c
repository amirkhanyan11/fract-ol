#include "fractol.h"


void fractal_init(char *name, t_fractal *fractal)
{
	fractal->name = name;
	fractal->connect.mlx = mlx_init();
	fractal->connect.win = mlx_new_window(fractal->connect.mlx, WIDTH, HEIGHT, fractal->name);
	fractal->img.img_ptr = mlx_new_image(fractal->connect.mlx, WIDTH, HEIGHT);

	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
												&fractal->img.bpp,
												&fractal->img.line_len,
												&fractal->img.endian);

}
