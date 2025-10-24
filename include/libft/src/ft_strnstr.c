/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:57:33 by texenber          #+#    #+#             */
/*   Updated: 2025/05/27 09:13:15 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *) haystack + i);
		i++;
		j = 0;
	}
	return (0);
}
/*#include <string.h>


int	main(void)
{
	char s1[30] = "aaabcabcd";
	char s2[10] = "aabc";
	int len = -1;

	printf("Found with ft_strnstr: %s\n", ft_strnstr(s1, s2, len));
//	printf("Found with strnstr: %s\n", strnstr(s1, s2, len));
	return (0);
}*/
