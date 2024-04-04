/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:43:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/04/04 16:59:52 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#define GL_KEY_L 37

int	key_handle(int keycode, t_fractal *fractal)
{
	if (GL_ESCAPE == keycode)
		destroy_handle(fractal);
	else if (GL_ARROWLEFT == keycode)
		fractal->shift_x -= (0.7 * fractal->zoom);
	else if (GL_ARROWRIGHT == keycode)
		fractal->shift_x += (0.7 * fractal->zoom);
	else if (GL_ARROWUP == keycode)
		fractal->shift_y += (0.7 * fractal->zoom);
	else if (GL_ARROWDOWN == keycode)
		fractal->shift_y -= (0.7 * fractal->zoom);
	else if (GL_PLUS == keycode)
		fractal->resolution += 25;
	else if (GL_MINUS == keycode)
		fractal->resolution -= 25;
	else if (GL_KEY_L == keycode)
		fractal->mouse_lock = !(fractal->mouse_lock);
	fractal_render(fractal);
	return (0);
}

int	destroy_handle(t_fractal *fractal)
{
	mlx_destroy_window(fractal->connect.mlx, fractal->connect.win);
	exit(EXIT_SUCCESS);
}

int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	if (GL_MOUSEWHEELUP == button)
		fractal->zoom *= 0.7;
	else if (GL_MOUSEWHEELDOWN == button)
		fractal->zoom *= 1.3;
	fractal_render(fractal);
	return (0);
}

int	julia_handle(int x, int y, t_fractal *fractal)
{
	if (fractal->mouse_lock == 0)
	{
		fractal->julia.real = (__rescale(x, -2, 2, WIDTH) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia.i = (__rescale(y, 2, -2, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
		fractal->color_compl *= 5;
		fractal_render(fractal);
	}
	return (0);
}

void	event_handle(t_fractal *fractal)
{
	mlx_hook(fractal->connect.win, ON_KEYDOWN, DUMMY, key_handle, fractal);
	mlx_hook(fractal->connect.win, ON_MOUSEDOWN, DUMMY, mouse_handle, fractal);
	mlx_hook(fractal->connect.win, ON_DESTROY, DUMMY, destroy_handle, fractal);
	if (!ft_strncmp(fractal->name, "julia", ft_strlen("julia")))
	{
		mlx_hook(fractal->connect.win, ON_MOUSEMOVE, DUMMY, julia_handle,
			fractal);
	}
}
