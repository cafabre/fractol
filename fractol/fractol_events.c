/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:43:16 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 17:50:59 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ESC)
		close_window(fractol);
	else if (keycode == KEY_LEFT)
		fractol->move_x -= 0.1 / fractol->zoom;
	else if (keycode == KEY_RIGHT)
		fractol->move_x += 0.1 / fractol->zoom;
	else if (keycode == KEY_UP)
		fractol->move_y -= 0.1 / fractol->zoom;
	else if (keycode == KEY_DOWN)
		fractol->move_y += 0.1 / fractol->zoom;
	else if (keycode == KEY_PLUS || keycode == KEY_EQUAL)
		fractol->zoom *= 1.1;
	else if (keycode == KEY_MINUS || keycode == KEY_DASH)
		fractol->zoom /= 1.1;
	draw_fractal(fractol);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	double	zoom_factor;
	double	mouse_re;
	double	mouse_im;

	zoom_factor = 1.1;
	mouse_re = (4.0 * x / WIDTH - 2.0) / fractol->zoom + fractol->move_x;
	mouse_im = (4.0 * y / HEIGHT - 2.0) / fractol->zoom + fractol->move_y;
	if (button == MOUSE_WHEEL_UP)
	{
		fractol->zoom *= zoom_factor;
		fractol->move_x = mouse_re - (4.0 * x / WIDTH - 2.0) / fractol->zoom;
		fractol->move_y = mouse_im - (4.0 * y / HEIGHT - 2.0) / fractol->zoom;
	}
	else if (button == MOUSE_WHEEL_DOWN)
	{
		fractol->zoom /= zoom_factor;
		fractol->move_x = mouse_re - (4.0 * x / WIDTH - 2.0) / fractol->zoom;
		fractol->move_y = mouse_im - (4.0 * y / HEIGHT - 2.0) / fractol->zoom;
	}
	draw_fractal(fractol);
	return (0);
}
