/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:02:15 by texenber          #+#    #+#             */
/*   Updated: 2025/11/11 13:10:13 by texenber         ###   ########.fr       */
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
	char	*cmd_path;
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
void	exit_perror(t_pipex *data, char *msg);

//	*** making the child processes and executing the commands ***
void	execute_pipex(t_pipex *data, char **envp);

//	*** getting the actual command adding the path to it ***
void	find_cmd_path_in_child(t_pipex *data, char **envp, char **cmd_av);

#endif //PIPEX_H