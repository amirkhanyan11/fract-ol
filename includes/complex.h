#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include "fractol.h"

typedef struct s_comlpex
{
	double real;
	double i;
} t_complex;


t_complex pow2_complex(t_complex num);
t_complex sum_complex(t_complex lhv, t_complex rhv);
int out_of_range(t_complex num);

#endif // _COMPLEX_H_
