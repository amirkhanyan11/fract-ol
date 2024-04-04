/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:43:21 by aamirkha          #+#    #+#             */
/*   Updated: 2024/04/04 16:43:21 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
double	atodouble(char *s);

#endif // _COMPLEX_H_
