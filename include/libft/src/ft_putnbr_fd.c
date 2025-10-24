/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:08:26 by texenber          #+#    #+#             */
/*   Updated: 2025/05/24 11:09:18 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar_fd(nb + '0', fd);
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
/*int	main(void)
{
	int	fd;

	fd = 1;
	ft_putnbr_fd(42, fd);
	write (fd, "\n", 1);
	ft_putnbr_fd(-42, fd);
	write (fd, "\n", 1);
	ft_putnbr_fd(0, fd);
	write (fd, "\n", 1);
	ft_putnbr_fd(2147483647, fd);
	write (fd, "\n", 1);
	ft_putnbr_fd(-2147483647, fd);
	write (fd, "\n", 1);
	ft_putnbr_fd(-2147483648, fd);
	write (fd, "\n", 1);
}*/
