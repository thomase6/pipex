/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:23:36 by texenber          #+#    #+#             */
/*   Updated: 2025/05/27 08:10:11 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int i)
{
	if (i >= 97 && i <= 122)
		i -= 32;
	return (i);
}
/*#include <stdio.h>

int main(void)
{
	printf("%c\n", ft_toupper('v'));
    return (0);
}*/
