/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:43:38 by texenber          #+#    #+#             */
/*   Updated: 2025/05/27 08:36:31 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	str = ft_calloc((len + 1), (sizeof(char)));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char	src[] = "I HAVE AN ARMY!!!!!!";

	printf("src = %s\n", src);
	char *target = ft_strdup(src);
	printf("dst = %s\n", target);
	free (target);
}
*/
