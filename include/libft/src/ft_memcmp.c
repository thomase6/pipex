/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:31:33 by texenber          #+#    #+#             */
/*   Updated: 2025/05/18 11:41:11 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (n == 0)
		return (0);
	n--;
	while (i < n && a[i] == b[i])
	{
		i++;
	}
	return (a[i] - b[i]);
}
/*#include <string.h>
int	main(void)
{
	char	s1[] = "ABCDEFGHI";
	char	s2[] = "ABCDEFgHI";
	int	cmp;

	cmp = ft_memcmp(s1, s2, 9);
	if (cmp > 0)
		printf("%s is greater than %s\n", s1, s2);
	else if (cmp < 0)
		printf("%s is greater than %s\n", s2, s1);
	else
		printf("%s is equal to %s\n", s1, s2);
	return(0);
}*/
