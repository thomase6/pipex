/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:46:09 by texenber          #+#    #+#             */
/*   Updated: 2025/05/28 07:49:45 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*newstr;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	newstr = ft_calloc((len + 1), (sizeof(char)));
	if (!newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	return (newstr);
}
/*
#include <stdio.h>
char	helpmepls(unsigned int i, char c)
{
	char	d;

	
	d = ft_toupper (c);
	return (d);
}
int	main(void)
{
	char *str = "42vienna";
	char *result;

	result = ft_strmapi(str, helpmepls);
	printf("%s\n", result);
	free(result);
}
*/
