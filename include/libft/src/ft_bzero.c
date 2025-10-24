/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:35:47 by texenber          #+#    #+#             */
/*   Updated: 2025/05/19 09:32:21 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/*#include <string.h>
int main (void)
{
    char buffer[20] = "wtf is this";
        printf("before bzero: %s\n", buffer);
        ft_bzero(buffer, 3);
//        bzero(buffer, 3);
        size_t i;

        i = 0;
        while(i < 12)
        {
        printf("after bzero: %c\n", buffer[i]);
//        printf("after bzero: %c\n", buffer[i]);
        i++;
        }
    return (0);
}*/
