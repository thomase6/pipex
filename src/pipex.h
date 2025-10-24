/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:02:15 by texenber          #+#    #+#             */
/*   Updated: 2025/10/24 16:07:53 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../include/libft/src/libft.h"
# include "../include/ft_printf/libftprintf.h"

typedef struct s_pipex
{
	char	*file1;
	char	*file2;
	char	*cmd1_str;
	char	*cmd2_str;
	int		fd_in;
	int		fd_out;
	
}	t_pipex;

#endif //PIPEX_H