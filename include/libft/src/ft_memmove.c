/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:23:35 by texenber          #+#    #+#             */
/*   Updated: 2025/05/27 09:54:16 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t n)
{
	unsigned char		*temp_dst;
	unsigned const char	*temp_src;
	size_t				i;

	i = 0;
	temp_dst = (unsigned char *) dst;
	temp_src = (unsigned const char *) src;
	if (temp_dst > temp_src)
	{
		while (n-- > 0)
			temp_dst[n] = temp_src[n];
	}
	else if (temp_dst < temp_src)
	{
		while (i < n)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	*dst= NULL;
	const char	src[50] = "I am the newline.";

	printf("Before memmove dst = %s, src = %s\n", dst, src);
	ft_memmove(dst, src, 17);
	printf("After memmove dst = %s, src = %s\n", dst, src);
}*/
