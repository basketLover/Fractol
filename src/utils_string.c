/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariserr <mariserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:11:30 by mariserr          #+#    #+#             */
/*   Updated: 2024/11/13 12:31:18 by mariserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *str1, char *str2, int n)
{
	if (str1 == NULL || str2 == NULL || n <= 0)
		return (0);
	while (*str1 == *str2 && n > 0 && *str1 != '\0')
	{
		++str1;
		++str2;
		--n;
	}
	return (*str1 - *str2);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (str == NULL || fd < 0)
		return ;
	if (*str != '\0')
	{
		write (fd, str, 1);
		ft_putstr_fd(str + 1, fd);
	}
}

double	ft_atoi_float(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if (*s == '.')
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
