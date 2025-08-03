/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:43:26 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 17:51:08 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	interpolate(int color1, int color2, double ratio)
{
	t_color	c1;
	t_color	c2;

	c1.r = (color1 / 65536) % 256;
	c1.g = (color1 / 256) % 256;
	c1.b = color1 % 256;
	c2.r = (color2 / 65536) % 256;
	c2.g = (color2 / 256) % 256;
	c2.b = color2 % 256;
	return (create_trgb(0, c1.r + (int)((c2.r - c1.r) * ratio),
		c1.g + (int)((c2.g - c1.g) * ratio),
		c1.b + (int)((c2.b - c1.b) * ratio)));
}

int	get_color(int iter, int max_iter)
{
	int		colors[5];
	double	t;
	int		index;
	double	ratio;

	colors[0] = 0xff00b7;
	colors[1] = 0x2300ff;
	colors[2] = 0x00ee07;
	colors[3] = 0x714cce;
	colors[4] = 0xc50016;
	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / max_iter * 4;
	index = (int)t;
	if (index >= 4)
		index = 3;
	ratio = t - index;
	return (interpolate(colors[index], colors[index + 1], ratio));
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
