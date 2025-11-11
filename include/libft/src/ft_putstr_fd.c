/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:14:41 by texenber          #+#    #+#             */
/*   Updated: 2025/11/10 12:14:26 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write (fd, s, ft_strlen(s));
}

/*int	main(void)
{
	char	s[] = "can I get a piece of gum?";
	int	fd;

	fd = 1;
	ft_putstr_fd(s, fd);
	return (0);
}*/
