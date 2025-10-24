/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:32:13 by texenber          #+#    #+#             */
/*   Updated: 2025/05/27 08:44:17 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int f)
{
	ssize_t			i;
	unsigned char	a;

	a = f;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == a)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>
int main(void)
{
    printf("%s\n", ft_strrchr("1234567", '2'));
    printf("%s\n", ft_strrchr(" ", ' '));
    printf("%s\n", strrchr("1234567", '2'));
    printf("%s\n", strrchr(" ", ' '));
}
*/
