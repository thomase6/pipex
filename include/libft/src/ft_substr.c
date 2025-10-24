/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:54:22 by texenber          #+#    #+#             */
/*   Updated: 2025/05/27 08:25:42 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	count;
	char	*str;

	i = start;
	count = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = ft_calloc((len + 1), (sizeof(char)));
	if (!str)
		return (NULL);
	while (count < len && s[i])
	{
		if (i >= start && count < len)
		{
			str[count] = s[i];
			count++;
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main (void)
{
	char	*str;

	str = ft_substr("tripouille", 0, 10);
	printf("substring: %s\n", str);
	free (str);
	return (0);
}
*/
