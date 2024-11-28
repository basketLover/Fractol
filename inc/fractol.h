/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariserr <mariserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:07:06 by mariserr          #+#    #+#             */
/*   Updated: 2024/11/24 20:01:06 by mariserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"\
./fractol burning_ship\" or\n\t\"./fractol julia <value_1> <value_2>\"\n"

# define WIDTH	800
# define HEIGHT	800

# define KEY_ESC           53  // Escape key
# define KEY_RIGHT         124 // Right arrow key
# define KEY_D             2   // 'D' key
# define KEY_LEFT          123 // Left arrow key
# define KEY_A             0   // 'A' key
# define KEY_DOWN          125 // Down arrow key
# define KEY_S             1   // 'S' key
# define KEY_UP            126 // Up arrow key
# define KEY_W             13  // 'W' key
# define KEY_PLUS          69  // '+' key 
# define KEY_MINUS         78  // '-' key

# define KEY_MOUSE_SCROLL_UP    4  // Zoom In
# define KEY_MOUSE_SCROLL_DOWN  5  // Zoom Out

//COLORS
# define BLACK      0x000000    // RGB(0, 0, 0)
# define WHITE      0xFFFFFF    // RGB(255, 255, 255)
# define RED        0xFF0000    // RGB(255, 0, 0)
# define GREEN      0x00FF00    // RGB(0, 255, 0)
# define BLUE       0x0000FF    // RGB(0, 0, 255)

# define MAGENTA_BURST      0xFF00FF    // A vibrant magenta
# define LIME_SHOCK         0xCCFF00    // A blinding lime
# define NEON_ORANGE        0xFF6600    // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066    // A deep purple
# define AQUA_DREAM         0x33CCCC    // A bright turquoise
# define HOT_PINK           0xFF66B2    // As the name suggests!
# define ELECTRIC_BLUE      0x0066FF    // A radiant blue
# define LAVA_RED           0xFF3300    // A bright, molten red

typedef struct s_complex
{
	double	x;
	double	y;
}		t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		nbr_iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractol;

int			ft_strncmp(char *str1, char *str2, int n);
void		ft_putstr_fd(char *str, int fd);
double		ft_atoi_float(char *s);

double		map(double unscaled, double new_min, \
				double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);

t_complex	square_complex(t_complex z);

void		fractol_init(t_fractol *fractol);

void		rendering(t_fractol *fractol);

int			key_handler(int key, t_fractol *fractal);

int			close_handler(t_fractol *fractol);
int			mouse_handler(int button, int x, int y, t_fractol *fractol);
int			julia_track(int x, int y, t_fractol *fractol);
void		rendement_burning_ship(t_fractol *fractal);
void		gerer_pixel_burning_ship(int x, int y, t_fractol *fractol);
void		put_pixel(int x, int y, t_img *img, int color);
void		cleanup(t_fractol *fractol);
void		init_julia(t_fractol *fractol, char **av);
void		render_fractal(t_fractol *fractol);
#endif