/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:11:16 by texenber          #+#    #+#             */
/*   Updated: 2025/05/28 08:07:06 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	len = ft_strlen(src);
	return (len);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
    char *src = NULL;
    char dst[20]; ft_bzero(dst, 20);
	size_t	len;

	printf("Pre: %s\n", dst);
    len = ft_strlcpy(dst, src, 1);
	printf("Post: %s\n", dst);
	printf("Length: %zu\n", len);

	return (0);
}
*/
