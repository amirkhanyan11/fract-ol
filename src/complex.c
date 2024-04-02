#include "fractol.h"

t_complex pow2_complex(t_complex num)
{
	t_complex res;

	res.real = (num.real * num.real) - (num.i * num.i);
	res.i = 2 * (num.real * num.i);

	return res;
}

t_complex sum_complex(t_complex lhv, t_complex rhv)
{
	t_complex res;

	res.real = lhv.real + rhv.real;
	res.i = lhv.i + rhv.i;

	return res;
}


int out_of_range(t_complex num)
{
	return ((num.real * num.real) + (num.i * num.i) > HYPOTHENUSE);
}
