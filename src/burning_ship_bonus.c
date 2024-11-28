/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariserr <mariserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:24:16 by mariserr          #+#    #+#             */
/*   Updated: 2024/11/24 19:59:24 by mariserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	gerer_pixel_burning_ship(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (map(x, -2.0, +2.0, WIDTH) * fractol->zoom) + fractol->shift_x;
	c.y = (map(y, -2.0, +2.0, HEIGHT) * fractol->zoom) + fractol->shift_y;
	while (i < fractol->nbr_iterations)
	{
		temp.x = z.x;
		z.x = fabs(z.x * z.x) - fabs(z.y * z.y) + c.x;
		z.y = fabs(2 * temp.x * z.y) + c.y;
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = map(i, WHITE, LIME_SHOCK, fractol->nbr_iterations);
			put_pixel(x, y, &fractol->img, color);
			return ;
		}
		++i;
	}
	put_pixel(x, y, &fractol->img, BLACK);
}

void	rendement_burning_ship(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			gerer_pixel_burning_ship(x, y, fractol);
		mlx_put_image_to_window(fractol->mlx_connection, \
								fractol->mlx_window, \
								fractol->img.img_ptr, 0, 0);
	}
}
