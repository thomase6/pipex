/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:19:36 by texenber          #+#    #+#             */
/*   Updated: 2025/05/18 13:21:59 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int i)
{
	if (i >= 65 && i <= 90)
		i += 32;
	return (i);
}
/*#include <stdio.h>

int main(void)
{
    printf("%c\n", ft_tolower('A'));
    return (0);
}*/
