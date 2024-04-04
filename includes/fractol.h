/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:43:17 by aamirkha          #+#    #+#             */
/*   Updated: 2024/04/04 17:00:06 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTOL_H_
# define _FRACTOL_H_

# include "../mlx/mlx.h"
# include "complex.h"
# include "ft_printf.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 720
# define HEIGHT 720
# define HYPOTHENUSE 4

# define DUMMY 0

/*
 * COLORS
 */
# define BLACK 0x000000 // RGB(0, 0, 0)
# define WHITE 0xFFFFFF // RGB(255, 255, 255)
# define RED 0xFF0000   // RGB(255, 0, 0)
# define GREEN 0x00FF00 // RGB(0, 255, 0)
# define BLUE 0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA_BURST 0xFF00FF      // A vibrant magenta
# define LIME_SHOCK 0xCCFF00         // A blinding lime
# define NEON_ORANGE 0xFF6600        // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066 // A deep purple
# define AQUA_DREAM 0x33CCCC         // A bright turquoise
# define HOT_PINK 0xFF66B2           // As the name suggests!
# define ELECTRIC_BLUE 0x0066FF      // A radiant blue
# define LAVA_RED 0xFF3300           // A bright, molten red

typedef struct s_img
{
	void		*img_ptr;
	char		*pixels_ptr;
	int			bpp;
	int			endian;
	int			line_len;
}				t_img;

enum	e_e
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_connect
{
	void		*mlx;
	void		*win;
}				t_connect;

typedef struct s_fractal
{
	// technical part

	t_connect	connect;
	t_img		img;

	// members

	char		*name;
	int			resolution;
	int			color_main;
	int			color_compl;

	double		shift_x;
	double		shift_y;
	double		zoom;
	short		mouse_lock;

	t_complex	julia;

}				t_fractal;


// init
void			fractal_init(char *name, t_complex *julia, t_fractal *fractal);
void			connection_init(t_fractal *fractal);

// events
void			event_handle(t_fractal *fractal);
int				julia_handle(int x, int y, t_fractal *fractal);
int				mouse_handle(int button, int x, int y, t_fractal *fractal);
int				destroy_handle(t_fractal *fractal);
int				key_handle(int keycode, t_fractal *fractal);

// render
double			__rescale(double unscaledNum, double minAllowed,
					double maxAllowed,  double max);
void			handle_pixel(int x, int y, t_img *img, int color);
void			constant_init(t_complex *z, t_complex *c, t_fractal *fractal);
void			render(int x, int y, t_fractal *fractal);
void			fractal_render(t_fractal *fractal);

#endif // _FRACTOL_H_
