/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 09:19:16 by texenber          #+#    #+#             */
/*   Updated: 2025/05/28 14:04:10 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	const char		*s;

	i = 0;
	d = (unsigned char *)dst;
	s = (const char *)src;
	while (n > 0)
	{
		d[i] = s[i];
		n--;
		i++;
	}
	return (dst);
}
/*#include <string.h>
int	main(void)
{
	const char	src[50] = "\n";
	char	dst[50];
	int	n;

	n = 2; 
	printf("dst before memcpy = %s\n", dst);
	ft_memcpy(dst, src, n);
	printf("dst after memcpy = %s\n", dst);
	return (0);
}*/
