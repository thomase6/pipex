/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:02:15 by texenber          #+#    #+#             */
/*   Updated: 2025/11/07 16:36:48 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include "../include/libft/src/libft.h"

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
	int		status1;
	int		status2;
}	t_pipex;

//	***	Error handling, freeing, closing and exit	***
void	free_all(t_pipex *data);
void	free_argv(char **av);
void	exit_all_error(t_pipex *data, char *msg, int exit_code);
void	close_all(t_pipex *data);
void	ft_perror(char *msg);

//	*** making the child processes and executing the commands ***
void	execute_pipex(t_pipex *data, char **envp);

//	*** getting the actual command adding the path to it ***
void	find_cmd_path(t_pipex *data, char **envp);

#endif //PIPEX_H