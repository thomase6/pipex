/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_putchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 09:49:38 by texenber          #+#    #+#             */
/*   Updated: 2025/06/10 09:57:52 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	count_putchar(char c)
{
	int	count;

	count = 1;
	write(1, &c, 1);
	return (count);
}
