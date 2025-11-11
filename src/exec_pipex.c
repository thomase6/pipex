/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:45:10 by texenber          #+#    #+#             */
/*   Updated: 2025/11/11 13:12:22 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_perror(t_pipex *data, char *msg)
{
	int	exit_code;

	exit_code = 0;
	if (!data->cmd_path)
	{
		errno = 2;
		perror(msg);
		exit_code = 127;
	}
	else if (errno == ENOENT)
	{
		perror(msg);
		exit_code = 127;
	}
	else if (errno == EACCES)
	{
		perror(msg);
		exit_code = 126;
	}
	free_all(data);
	close_all(data);
	exit(exit_code);
}

static void	child1(t_pipex *data, char **envp)
{
	// find_cmd_path_in_child(data, envp, data->cmd1_av);
	data->fd_in = open(data->file1, O_RDONLY);
	if (data->fd_in < 0)
		exit_all_error(data, "no such file or directory\n", 1);
	find_cmd_path_in_child(data, envp, data->cmd1_av);
	dup2(data->fd_in, STDIN_FILENO);
	dup2(data->pipe_fd[1], STDOUT_FILENO);
	close_all(data);
	if (access(data->cmd_path, F_OK))
		exit_perror(data, data->cmd1_av[0]);
	else if ((access(data->cmd_path, X_OK)))
		exit_perror(data, data->cmd1_av[0]);
	execve(data->cmd_path, data->cmd1_av, envp);
	exit_perror(data, "execve failed");
}

static void	child2(t_pipex *data, char **envp)
{
	// find_cmd_path_in_child(data, envp, data->cmd2_av);
	data->fd_out = open(data->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fd_out < 0)
		exit_all_error(data, "Permission Denied\n", 1);
	find_cmd_path_in_child(data, envp, data->cmd2_av);
	dup2(data->pipe_fd[0], STDIN_FILENO);
	dup2(data->fd_out, STDOUT_FILENO);
	close_all(data);
	if (access(data->cmd_path, F_OK))
		exit_perror(data, data->cmd2_av[0]);
	else if ((access(data->cmd_path, X_OK)))
		exit_perror(data, data->cmd2_av[0]);
	execve(data->cmd_path, data->cmd2_av, envp);
	exit_perror(data, "execve failed");
}

void	execute_pipex(t_pipex *data, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
		exit_all_error(data, "Fork failed\n", 1);
	if (pid1 == 0)
		child1(data, envp);
	pid2 = fork();
	if (pid2 < 0)
		exit_all_error(data, "Fork failed\n", 1);
	if (pid2 == 0)
		child2(data, envp);
	close_all(data);
	waitpid(pid1, &data->status1, 0);
	waitpid(pid2, &data->status2, 0);
	if (WIFEXITED(data->status2))
		exit_all_error(data, NULL, WEXITSTATUS(data->status2));
}
