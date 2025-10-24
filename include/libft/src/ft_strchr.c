/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:08:02 by texenber          #+#    #+#             */
/*   Updated: 2025/05/28 13:59:41 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int f)
{
	size_t			i;
	unsigned char	a;

	a = f;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == a)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == a)
		return ((char *)&str[i]);
	return (0);
}
/*
#include<stdio.h>
#include<string.h>
int	main(void)
{
	printf("%s\n", ft_strchr("tripouille", 0));
	printf("%s\n", strchr("tripouille", 0));
//	printf("%s\n", strchr("this is a test", 'a'));
//	printf("%s\n", strchr("", 'a'));
}*/
