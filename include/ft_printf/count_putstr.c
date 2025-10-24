/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 07:22:03 by texenber          #+#    #+#             */
/*   Updated: 2025/06/10 09:58:17 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	count_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (count_putstr("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
