#include "fractol.h"

double rescale(double unscaledNum, double minAllowed,  double maxAllowed, double min, double max)
{
	return (maxAllowed - minAllowed) * (unscaledNum - min) / (max - min) + minAllowed;
}

static void	handle_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color; // esim axper
}

void constant_init(t_complex *z, t_complex *c, t_fractal * fractal)
{
	if (!ft_strncmp(fractal->name, "julia", ft_strlen("julia")))
	{
		c->real = fractal->julia.real;
		c->i = fractal->julia.i;
	}
	else
		*c = *z;
}

void render(int x, int y, t_fractal * fractal)
{
	t_complex z;
	t_complex c;
	int color;

	int i = 0;

	z.real = rescale(x, -2, 2, 0, WIDTH * fractal->zoom) + fractal->shift_x;
	z.i = rescale(y, 2, -2, 0, HEIGHT * fractal->zoom) + fractal->shift_y;

	constant_init(&z, &c, fractal);

	while (i < fractal->resolution)
	{
		z = sum_complex(pow2_complex(z), c);

		if (out_of_range(z))
		{
			color = rescale(i, BLACK, WHITE, 0, fractal->resolution);
			handle_pixel(x, y, &fractal->img, color);
			return;
		}
		i++;
	}
	handle_pixel(x, y, &fractal->img, fractal->color);

}


void fractal_render(t_fractal * fractal)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			render(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->connect.mlx, fractal->connect.win, fractal->img.img_ptr, 0, 0);
}
