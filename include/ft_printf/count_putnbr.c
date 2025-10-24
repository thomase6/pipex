/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 07:44:13 by texenber          #+#    #+#             */
/*   Updated: 2025/06/10 09:59:41 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	count_putnbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += count_putchar('-');
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
		count += count_putchar(nb + '0');
	if (nb > 9)
	{
		count += count_putnbr(nb / 10);
		count += count_putnbr(nb % 10);
	}
	return (count);
}
