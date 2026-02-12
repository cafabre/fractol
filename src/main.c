/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:43:31 by cafabre           #+#    #+#             */
/*   Updated: 2025/07/21 21:03:56 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	validate_args(int argc, char **argv)
{
	if (argc != 2 && argc != 4)
	{
		ft_printf("Available fractals: mandelbrot, julia, burning_ship\n");
		ft_printf("Julia: julia [real] [imaginary]\n");
		return (0);
	}
	if (argc == 4 && ft_strcmp(argv[1], "julia") != 0)
	{
		ft_printf("Error: Only julia accepts parameters\n");
		return (0);
	}
	if (argc == 4 && (!is_valid_number(argv[2]) || !is_valid_number(argv[3])))
	{
		ft_printf("Error: Invalid number format\n");
		return (0);
	}
	if (ft_strcmp(argv[1], "mandelbrot") != 0
		&& ft_strcmp(argv[1], "julia") != 0
		&& ft_strcmp(argv[1], "burning_ship") != 0)
	{
		ft_printf("Available fractals: mandelbrot, julia, burning_ship\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (!validate_args(argc, argv))
		return (1);
	if (argc == 4)
	{
		if (init_fractol(&fractol, argv[1], argv[2], argv[3]) == -1)
			return (1);
	}
	else
	{
		if (init_fractol(&fractol, argv[1], NULL, NULL) == -1)
			return (1);
	}
	draw_fractal(&fractol);
	mlx_key_hook(fractol.win, key_hook, &fractol);
	mlx_mouse_hook(fractol.win, mouse_hook, &fractol);
	mlx_hook(fractol.win, 17, 0, close_window, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
