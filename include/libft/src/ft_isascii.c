/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:51:46 by texenber          #+#    #+#             */
/*   Updated: 2025/05/18 11:32:01 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int i)
{
	if ((i >= 0 && i <= 127))
		return (1);
	return (0);
}

/*#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_isascii(0xF1));
    return (0); 
}*/
