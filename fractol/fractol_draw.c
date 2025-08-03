/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:43:09 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 17:54:19 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	pixel_to_complex(int x, int y, t_fractol *fractol)
{
	t_complex	c;

	c.r = (4.0 * x / WIDTH - 2.0) / fractol->zoom + fractol->move_x;
	c.i = (4.0 * y / HEIGHT - 2.0) / fractol->zoom + fractol->move_y;
	return (c);
}

void	draw_fractal(t_fractol *fractol)
{
	int			x;
	int			y;
	int			iter;
	t_complex	z;
	int			color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z = pixel_to_complex(x, y, fractol);
			if (fractol->fractal_type == 1)
				iter = mandelbrot((t_complex){0, 0}, z);
			else if (fractol->fractal_type == 2)
				iter = julia(z, fractol->c);
			else
				iter = burning_ship((t_complex){0, 0}, z);
			color = get_color(iter, MAX_ITER);
			my_mlx_pixel_put(fractol, x++, y, color);
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->addr + (y * fractol->line_length + x
			* (fractol->bits_per_pixel / 8));
	*(unsigned int *)dst = color ;
}
