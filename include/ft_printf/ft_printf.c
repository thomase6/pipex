/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:24:53 by texenber          #+#    #+#             */
/*   Updated: 2025/08/31 11:34:12 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	find_format(va_list args, const char *format, size_t i, int count)
{
	if (format[i] == 's')
		count += count_putstr(va_arg(args, char *));
	else if (format[i] == 'c')
		count += count_putchar(va_arg(args, int));
	else if (format[i] == 'i' || format[i] == 'd')
		count += count_putnbr(va_arg(args, int));
	else if (format[i] == 'u')
		count += count_putuint(va_arg(args, unsigned int));
	else if (format[i] == 'x')
		count += putlowerhex(va_arg(args, unsigned int));
	else if (format[i] == 'X')
		count += putupperhex(va_arg(args, unsigned int));
	else if (format[i] == 'p')
		count += putaddress(va_arg(args, void *));
	else if (format[i] == '%')
		count += count_putchar('%');
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count = find_format(args, format, ++i, count);
			if (count == -1)
				return (va_end(args), -1);
			if (format[i - 1] == '%')
				i++;
		}
		else
			count += write (1, &format[i++], 1);
	}
	return (va_end(args), count);
}
