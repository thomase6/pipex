/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 08:26:42 by texenber          #+#    #+#             */
/*   Updated: 2025/05/28 13:46:23 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_count(long nbr);

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	size_t	len;
	long	nbr;

	nbr = n;
	len = int_count(nbr);
	str = ft_calloc((len + 1), (sizeof(char)));
	if (!str)
		return (NULL);
	i = len - 1;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr)
	{
		str[i--] = ((nbr % 10) + '0');
		nbr /= 10;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}

static size_t	int_count(long nbr)
{
	size_t	count;

	count = 0;
	if (nbr == 0)
	{
		count = 1;
		return (count);
	}
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
/*
#include<stdio.h>
int main(void)
{
	int	n;
	char  *result;
		
	n = -2147483648;
	result = ft_itoa(n);
	printf("%s\n", result);
	free (result);
	return (0);
}*/
