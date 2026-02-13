#include "fractol.h"

static void	init_values(t_fractol *fractol, char *param1, char *param2)
{
	fractol->zoom = 1.0;
	fractol->move_x = 0.0;
	fractol->move_y = 0.0;
	if (fractol->fractal_type == 2 && !param1 && !param2)
	{
		fractol->c.r = -0.7;
		fractol->c.i = 0.27015;
	}
}

static int	set_fractal_type(t_fractol *fractol, char *fractal_name,
	char *param1, char *param2)
{
	if (!fractal_name)
		return (-1);
	if (ft_strncmp(fractal_name, "mandelbrot", 10) == 0)
		fractol->fractal_type = 1;
	else if (ft_strncmp(fractal_name, "julia", 5) == 0)
	{
		fractol->fractal_type = 2;
		if (param1 && param2)
		{
			fractol->c.r = ft_atof(param1);
			fractol->c.i = ft_atof(param2);
		}
	}
	else if (ft_strncmp(fractal_name, "burning_ship", 12) == 0)
		fractol->fractal_type = 3;
	else
		return (-1);
	return (0);
}

int	init_fractol(t_fractol *fractol, char *fractal_name, char *param1,
	char *param2)
{
	if (set_fractal_type(fractol, fractal_name, param1, param2) == -1)
		return (-1);
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		return (-1);
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fractol");
	if (!fractol->win)
		return (-1);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img)
		return (-1);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel,
			&fractol->line_length, &fractol->endian);
	init_values(fractol, param1, param2);
	return (0);
}
