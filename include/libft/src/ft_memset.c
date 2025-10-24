/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:26:59 by texenber          #+#    #+#             */
/*   Updated: 2025/05/18 12:58:33 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	a;

	a = (unsigned char)c;
	ptr = (unsigned char *)str;
	while (n > 0)
	{
		*ptr = a;
		ptr++;
		n--;
	}
	return ((void *)str);
}

/*#include <string.h>
int main(void)
{
	char str[] = "he will help";
	
	ft_memset(str, '*', 2);
	printf("%s\n", str);
	return (0);
}*/
