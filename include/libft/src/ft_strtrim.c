/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:07:47 by texenber          #+#    #+#             */
/*   Updated: 2025/05/28 08:51:54 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, (int)s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, (int)s1[end - 1]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	str = ft_substr(s1, start, (end - start));
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	const char	s1[] = "";
	const char	set[] = "ab";
	char	*result;
	
	result = ft_strtrim(s1, set);
	printf("trimmed string:%s\n", result);
	free (result);
}*/
