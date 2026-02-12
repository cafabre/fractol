/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:53:13 by cafabre           #+#    #+#             */
/*   Updated: 2026/02/12 19:59:45 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

# define KEY_ESC 65307
# define KEY_PLUS 65451
# define KEY_MINUS 65453
# define KEY_EQUAL 61
# define KEY_DASH 45
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364

# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			fractal_type;
	double		zoom;
	double		move_x;
	double		move_y;
	t_complex	c;
}				t_fractol;

int		init_fractol(t_fractol *fractol, char *fractal_name, char *param1,
			char *param2);
void	draw_fractal(t_fractol *fractol);
int		mandelbrot(t_complex z, t_complex c);
int		julia(t_complex z, t_complex c);
int		burning_ship(t_complex z, t_complex c);
void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		get_color(int iter, int max_iter);
int		key_hook(int keycode, t_fractol *fractol);
int		mouse_hook(int button, int x, int y, t_fractol *fractol);
int		close_window(t_fractol *fractol);
int		is_valid_number(char *str);

#endif