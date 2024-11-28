/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariserr <mariserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:33:09 by mariserr          #+#    #+#             */
/*   Updated: 2024/11/24 17:54:57 by mariserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Put a pixel in my image buffer
void	put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandelbrot_or_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2.0, +2.0, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.y = (map(y, +2.0, -2.0, HEIGHT) * fractol->zoom) + fractol->shift_y;
	mandelbrot_or_julia(&z, &c, fractol);
	while (i < fractol->nbr_iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = map(i, BLACK, LIME_SHOCK, fractol->nbr_iterations);
			put_pixel(x, y, &fractol->img, color);
			return ;
		}
		++i;
	}
	put_pixel(x, y, &fractol->img, BLACK);
}

void	rendering(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractol);
	}
	mlx_put_image_to_window(fractol->mlx_connection, \
								fractol->mlx_window, \
								fractol->img.img_ptr, 0, 0);
}
