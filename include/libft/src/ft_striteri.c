/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:11:05 by texenber          #+#    #+#             */
/*   Updated: 2025/05/27 07:53:30 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*#include <stdio.h>

void	str_toupper(unsigned int i, char *s)
{
	(void)i;

	if (*s >= 'a' && *s <= 'z')
		*s -= 32;
}

int	main(void)
{
	char	str[] = "iteri this";

	ft_striteri(str, str_toupper);
	printf("%s\n", str);
	return (0);
}*/
