#ifndef _FRACTOL_H_
#define _FRACTOL_H_

#include <stdio.h>
#include  "../mlx/mlx.h"
#include <stdlib.h>
#include <unistd.h>
# include <math.h>
#include "complex.h"

#define WIDTH	800
#define	HEIGHT	800
#define HYPOTHENUSE 4

#define DUMMY 0

/*
 * COLORS
*/
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct	s_connect {
	void	*mlx;
	void	*win;
}				t_connect;


typedef struct s_fractal
{
	// technical part

	t_connect connect;
	t_img img;

	// members

	char const * name;
	int resolution;
	int color;

	double shift_x;
	double shift_y;
	double zoom;

	t_complex julia;

}	t_fractal;



#endif // _FRACTOL_H_
