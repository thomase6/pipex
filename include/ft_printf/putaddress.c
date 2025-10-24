/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putaddress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 07:31:42 by texenber          #+#    #+#             */
/*   Updated: 2025/06/10 11:13:02 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	putaddress(void *str)
{
	int	count;

	if (!str)
		return (count_putstr("(nil)"));
	count = 2;
	write(1, "0x", 2);
	count += putaddresshex((unsigned long)str);
	return (count);
}
