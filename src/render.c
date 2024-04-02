#include "fractol.h"

double resize(double unscaledNum, double minAllowed,  double maxAllowed, double min, double max)
{
	return (maxAllowed - minAllowed) * (unscaledNum - min) / (max - min) + minAllowed;
}

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color; // esim axper
}


void render(int x, int y, t_fractal * fractal)
{
	t_complex z;
	t_complex c;
	int color;

	int i = 0;

	z.real = 0.0;
	z.i = 0.0;

	c.real = resize(x, -2, 2, 0, WIDTH);
	c.i = resize(y, 2, -2, 0, HEIGHT);

	while (i < RESOLUTION)
	{
		z = sum_complex(pow2_complex(z), c);

		if (out_of_range(z))
		{
			color = resize(i, BLACK, WHITE, 0, RESOLUTION);
			my_pixel_put(x, y, &fractal->img, color);
			return;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, HOT_PINK);

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
