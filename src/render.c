/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:43:10 by aamirkha          #+#    #+#             */
/*   Updated: 2024/04/04 17:02:29 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	__rescale(double unscaledNum, double minAllowed, double maxAllowed,
		double max)
{
	return ((maxAllowed - minAllowed) * unscaledNum / max + minAllowed);
}

void	handle_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	constant_init(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", ft_strlen("julia")))
	{
		c->real = fractal->julia.real;
		c->i = fractal->julia.i;
	}
	else
		*c = *z;
}

void	render(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			i;

	i = 0;
	z.real = (__rescale(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.i = (__rescale(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	constant_init(&z, &c, fractal);
	while (i < fractal->resolution)
	{
		z = sum_complex(pow2_complex(z), c);
		if (out_of_range(z))
		{
			if (i * fractal->color_compl > fractal->resolution)
				color = i;
			else
				color = i * fractal->color_compl;
			color = __rescale(color, BLACK, WHITE, fractal->resolution);
			handle_pixel(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	handle_pixel(x, y, &fractal->img, fractal->color_main);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			render(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->connect.mlx, fractal->connect.win,
		fractal->img.img_ptr, 0, 0);
}
