/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:25:05 by texenber          #+#    #+#             */
/*   Updated: 2025/05/18 11:35:19 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	a;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	a = (unsigned char)c;
	while (n > 0)
	{
		if (str[i] == a)
			return (&str[i]);
		i++;
		n--;
	}
	return (0);
}

/* #include <string.h>
int	main(void)
{
	char str[] = "jsdjs";
	char *find;
	int pos;

	printf("the input: %s\n", str);
	find = memchr(str, '6', sizeof(str));
	if (find != NULL)
	{
		printf("the char found: %s\n", find);
		pos = (int)(find - str);
		printf("found in position: %d\n", pos);
	}
	else 
		printf("the char you are looking for is in another castle.");
	return (0);
}*/
