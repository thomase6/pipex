/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:39:39 by texenber          #+#    #+#             */
/*   Updated: 2025/05/27 08:19:02 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	if (count == 0 || size == 0)
		return (malloc (0));
	total = count * size;
	if (total / count != size)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (total));
	return (ptr);
}
/*
#include <stdio.h>
int main()
{
	size_t	n;
	unsigned char *ptr;

	n = 5;
	ptr = (unsigned char *)ft_calloc(n, sizeof(unsigned char));
	if (ptr == NULL)
	{
		printf("Null pointer \n");
		return(1);
	}
	else
	{
		printf("Address = %p", (void *)ptr);
	}
	free(ptr);
	return(0);
}
*/
