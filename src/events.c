/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariserr <mariserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:56:34 by mariserr          #+#    #+#             */
/*   Updated: 2024/11/24 20:15:35 by mariserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int key, t_fractol *fractol)
{
	if (key == KEY_ESC)
		close_handler(fractol);
	if (key == KEY_RIGHT || key == KEY_D)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (key == KEY_LEFT || key == KEY_A)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (key == KEY_DOWN || key == KEY_S)
		fractol->shift_y += (0.5 * fractol->zoom);
	else if (key == KEY_UP || key == KEY_W)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (key == KEY_PLUS)
		fractol->nbr_iterations += 15;
	else if (key == KEY_MINUS)
		fractol->nbr_iterations -= 15;
	if (!ft_strncmp(fractol->name, "burning_ship", 12))
		rendement_burning_ship(fractol);
	else
		rendering(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == KEY_MOUSE_SCROLL_UP)
		fractol->zoom *= 1.5;
	else if (button == KEY_MOUSE_SCROLL_DOWN)
		fractol->zoom *= 0.5;
	if (!ft_strncmp(fractol->name, "burning_ship", 12))
		rendement_burning_ship(fractol);
	else
		rendering(fractol);
	return (0);
}

int	close_handler(t_fractol *fractol)
{
	cleanup(fractol);
	exit(EXIT_SUCCESS);
	return (0);
}

int	julia_track(int x, int y, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		fractol->julia_x = (map(x, -2, +2, WIDTH) * fractol->zoom) \
							+ fractol->shift_x;
		fractol->julia_y = (map(y, +2, -2, HEIGHT) * fractol->zoom) \
							+ fractol->shift_y;
		rendering(fractol);
	}
	return (0);
}
