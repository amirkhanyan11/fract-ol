/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:42:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/04/04 16:42:57 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pow2_complex(t_complex num)
{
	t_complex	res;

	res.real = (num.real * num.real) - (num.i * num.i);
	res.i = 2 * (num.real * num.i);
	return (res);
}

t_complex	sum_complex(t_complex lhv, t_complex rhv)
{
	t_complex	res;

	res.real = lhv.real + rhv.real;
	res.i = lhv.i + rhv.i;
	return (res);
}

int	out_of_range(t_complex num)
{
	return ((num.real * num.real) + (num.i * num.i) > HYPOTHENUSE);
}

double	atodouble(char *s)
{
	long	integer_part;
	double	fraction;
	double	pow;
	int		sign;

	integer_part = 0;
	fraction = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fraction = fraction + (*s++ - 48) * pow;
	}
	return ((integer_part + fraction) * sign);
}
