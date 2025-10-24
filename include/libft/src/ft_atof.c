/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:33:34 by texenber          #+#    #+#             */
/*   Updated: 2025/09/03 08:39:16 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	find_fract(char *str, int i, double pow)
{
	double	fract_part;

	fract_part = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		pow /= 10;
		fract_part += (str[i++] - '0') * pow;
	}
	return (fract_part);
}

double	ft_atof(char *str)
{
	int		i;
	int		sign;
	double	integer_part;
	double	fractional_part;
	double	pow;

	i = 0;
	sign = 1;
	pow = 1;
	integer_part = 0;
	while (ft_is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] != '.')
		integer_part = (integer_part * 10) + (str[i++] - 48);
	if (str[i] == '.')
		i++;
	fractional_part = find_fract(str, i, pow);
	return ((integer_part + fractional_part) * sign);
}
