/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:04:33 by texenber          #+#    #+#             */
/*   Updated: 2025/06/10 11:45:44 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	count_putchar(char c);
int	count_putstr(char *str);
int	putupperhex(unsigned int un);
int	putlowerhex(unsigned int un);
int	putaddresshex(unsigned long n);
int	putaddress(void *str);
int	count_putuint(unsigned int un);
int	count_putnbr(int n);

#endif
