/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariserr <mariserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:09:19 by mariserr          #+#    #+#             */
/*   Updated: 2024/11/25 17:30:54 by mariserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_args(int ac, char **av, t_fractol *fractol)
{
	fractol->name = av[1];
	if (!fractol->name || \
		((ac != 2 || (ft_strncmp(av[1], "mandelbrot", 10) && \
					ft_strncmp(av[1], "burning_ship", 12))) && \
		(ac != 4 || ft_strncmp(av[1], "julia", 5))))
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	init_julia(t_fractol *fractol, char **av)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		fractol->julia_x = ft_atoi_float(av[2]);
		fractol->julia_y = ft_atoi_float(av[3]);
	}
}

void	render_fractal(t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "mandelbrot", 10) || \
		!ft_strncmp(fractol->name, "julia", 5))
	{
		rendering(fractol);
	}
	else
	{
		rendement_burning_ship(fractol);
	}
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	check_args(ac, av, &fractol);
	init_julia(&fractol, av);
	fractol_init(&fractol);
	render_fractal(&fractol);
	mlx_loop(fractol.mlx_connection);
	cleanup(&fractol);
	return (0);
}
