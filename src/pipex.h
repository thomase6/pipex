/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:02:15 by texenber          #+#    #+#             */
/*   Updated: 2025/11/05 13:03:12 by texenber         ###   ########.fr       */
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
	char	**cmd1_av;
	char	**cmd2_av;
	char	*cmd1_path;
	char	*cmd2_path;
	int		fd_in;
	int		fd_out;
	int		pipe_fd[2];
	
}	t_pipex;

//	***	Error handling and exit	***
void	free_argv(char **av);
void	free_all(t_pipex *data);
void	exit_all_error(t_pipex *data, const char *msg, int exit_code);
void	close_all(t_pipex *data);


#endif //PIPEX_H