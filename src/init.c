/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:43:14 by aamirkha          #+#    #+#             */
/*   Updated: 2024/04/04 16:43:15 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	connection_init(t_fractal *fractal)
{
	fractal->connect.mlx = mlx_init();
	fractal->connect.win = mlx_new_window(fractal->connect.mlx, WIDTH, HEIGHT,
			fractal->name);
	fractal->img.img_ptr = mlx_new_image(fractal->connect.mlx, WIDTH, HEIGHT);
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
}

void	fractal_init(char *name, t_complex *julia, t_fractal *fractal)
{
	fractal->name = name;
	fractal->resolution = 42;
	fractal->color_main = BLACK;
	fractal->color_compl = 1;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->zoom = 1;
	fractal->mouse_lock = 0;
	if (!ft_strncmp(fractal->name, "julia", ft_strlen("julia")))
	{
		fractal->julia.real = julia->real;
		fractal->julia.i = julia->i;
	}
	connection_init(fractal);
	event_handle(fractal);
}
