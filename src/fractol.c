#include "fractol.h"

int	close(int keycode, t_connect *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}



int	main(void)
{
	t_fractal fractal;
	fractal_init("gago", &fractal);

	fractal_render(&fractal);
	mlx_loop(fractal.connect.mlx);

	return (0);
}
