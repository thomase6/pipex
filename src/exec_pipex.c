/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:45:10 by texenber          #+#    #+#             */
/*   Updated: 2025/11/07 11:58:13 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1(t_pipex *data, char **envp)
{
	dup2(data->fd_in, STDIN_FILENO);
	dup2(data->pipe_fd[1], STDOUT_FILENO);
	close_all(data);
	if (access(data->cmd1_path, F_OK))
		exit_all_error(data, "command not found", 127);
	else if ((access(data->cmd1_path, X_OK)))
		exit_all_error(data, "permission denied", 126);
	execve(data->cmd1_path, data->cmd1_av, envp);
	exit_all_error(data, "execve failed", 1);
}

static void	child2(t_pipex *data, char **envp)
{
	dup2(data->pipe_fd[0], STDIN_FILENO);
	dup2(data->fd_out, STDOUT_FILENO);
	close_all(data);
	if (access(data->cmd2_path, F_OK))
		exit_all_error(data, "command not found", 127);
	else if ((access(data->cmd2_path, X_OK)))
		exit_all_error(data, "permission denied", 126);
	execve(data->cmd2_path, data->cmd2_av, envp);
	exit_all_error(data, "execve failed", 1);
}

void	execute_pipex(t_pipex *data, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;

	data->fd_in = open(data->file1, O_RDONLY);
	if (data->fd_in < 0)
		exit_all_error(data, "Open failed", 1);
	data->fd_out = open(data->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fd_out < 0)
		exit_all_error(data, "Open failed", 1);
	pid1 = fork();
	if (pid1 < 0)
		exit_all_error(data, "Fork failed", 1);
	if (pid1 == 0)
		child1(data, envp);
	pid2 = fork();
	if (pid2 < 0)
		exit_all_error(data, "Fork failed", 1);
	if (pid2 == 0)
		child2(data, envp);
	close_all(data);
	waitpid(pid1, &data->status1, 0);
	waitpid(pid2, &data->status2, 0);
	if (WIFEXITED(data->status2))
		exit_all_error(data, NULL, WEXITSTATUS(data->status2));
}
