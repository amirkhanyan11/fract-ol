#include "fractol.h"



int	main(int ac, char **av)
{
	t_fractal fractal;
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", ft_strlen("mandelbrot")))
	{
		fractal_init("mandelbrot", 0,  &fractal);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "julia", ft_strlen("julia")))
	{
		t_complex julia;
		julia.real = atodbl(av[2]);
		julia.i = atodbl(av[3]);
		fractal_init("julia", &julia,  &fractal);
	}
	else
		return -1;
	fractal_render(&fractal);
	mlx_loop(fractal.connect.mlx);
	return (0);
}
