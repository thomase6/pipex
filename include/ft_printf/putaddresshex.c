/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putaddresshex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 07:29:31 by texenber          #+#    #+#             */
/*   Updated: 2025/09/26 09:20:28 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	putaddresshex(unsigned long n)
{
	const char	*hex = "0123456789abcdef";
	int			count;

	count = 0;
	if (n >= 0 && n <= 15)
	{
		write(1, &hex[n], 1);
		count++;
	}
	if (n > 15)
	{
		count += putaddresshex(n / 16);
		count += putaddresshex(n % 16);
	}
	return (count);
}
