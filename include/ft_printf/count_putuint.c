/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_putuint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 07:42:10 by texenber          #+#    #+#             */
/*   Updated: 2025/06/10 10:00:11 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	count_putuint(unsigned int un)
{
	int	count;

	count = 0;
	if (un >= 0 && un <= 9)
		count += count_putchar(un + '0');
	if (un > 9)
	{
		count += count_putuint(un / 10);
		count += count_putuint(un % 10);
	}
	return (count);
}
