#include "fractol.h"

int	mandelbrot(t_complex z, t_complex c)
{
	int		iter;
	double	temp;

	iter = 0;
	while (iter < MAX_ITER && (z.r * z.r + z.i * z.i) <= 4.0)
	{
		temp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = temp;
		iter++;
	}
	return (iter);
}

int	julia(t_complex z, t_complex c)
{
	int		iter;
	double	temp;

	iter = 0;
	while (iter < MAX_ITER && (z.r * z.r + z.i * z.i) <= 4.0)
	{
		temp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = temp;
		iter++;
	}
	return (iter);
}

int	burning_ship(t_complex z, t_complex c)
{
	int		iter;
	double	temp;

	iter = 0;
	while (iter < MAX_ITER && (z.r * z.r + z.i * z.i) <= 4.0)
	{
		temp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * fabs(z.r) * fabs(z.i) + c.i;
		z.r = fabs(temp);
		iter++;
	}
	return (iter);
}
