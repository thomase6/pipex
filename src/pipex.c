/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:02:18 by texenber          #+#    #+#             */
/*   Updated: 2025/11/05 14:58:35 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_pipex(t_pipex *data, char ** envp)
{
	pid_t	pid1;
	pid_t	pid2;
	
	if	(pipe(data->pipe_fd) == -1)
		exit_all_error(data, "Pipe failed", 1);	// might have to change this because it outputs success
	data->fd_in = open(data->file1, O_RDONLY);
	if (data->fd_in < 0)
		exit_all_error(data, "Open failed", 1);	// might have to change this because it outputs success
	data->fd_out = open(data->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fd_out < 0)
		exit_all_error(data, "Open failed", 1);	// might have to change this because it outputs success
	pid1 = fork();
	if (pid1 < 0)
		exit_all_error(data, "Fork failed", 1);	// might have to change this because it outputs success		
	if (pid1 == 0)
	{
		dup2(data->fd_in, STDIN_FILENO);
		dup2(data->pipe_fd[1], STDOUT_FILENO);
		close_all(data);
		execve(data->cmd1_path, data->cmd1_av, envp);
		// exit_all_error(data, "execve failed", 127);
	}
	pid2 = fork();
	if (pid2 < 0)
		exit_all_error(data, "Fork failed", 1); // might have to change this because it outputs success
	if (pid2 == 0)
	{
		dup2(data->pipe_fd[0], STDIN_FILENO);
		dup2(data->fd_out, STDOUT_FILENO);
		close_all(data);
		execve(data->cmd2_path, data->cmd2_av, envp);
		// exit_all_error(data, "execve failed", 127);
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	// need to add the macro 
}

char **get_cmd_argv(char *av)
{
	char **new_cmd;
	
	if (!av)
		return (NULL);
	new_cmd = ft_split(av, ' ');
	if (!new_cmd)
		return (NULL);
	return (new_cmd);
}

char	*resolve_cmd(char *cmd, char **dir_path)
{
	int		i;
	char	*tmp;
	char	*result;

	i = -1;
	result = NULL;
	if (ft_strlen(cmd) == 0)
		return (ft_strdup(" "));
	if (ft_strchr(cmd, '/'))
		if(access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
	while (dir_path[++i])
	{
		tmp = ft_strjoin(dir_path[i], "/");
		result = ft_strjoin(tmp, cmd);
		free(tmp);
		if(!result)
			return(NULL);
		if (access(result, X_OK) == 0)
			return (result);
		free (result);
	}
	return (ft_strdup(cmd));
}

void	find_cmd_path(t_pipex *data, char **envp)
{
	char	*env_path;
	char	**dir_path;
	int		i;

	i = 0;
	env_path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			env_path = envp[i] + 5;
			break;
		}
		i++;
	}
	if (!env_path)
		exit_all_error(data, "PATH not found", 1); // might have to change this because it outputs success
	dir_path = ft_split(env_path, ':');
	if (!dir_path)
		exit_all_error(data, "failed to split PATH", 1); // might have to change this because it outputs success
	data->cmd1_path = resolve_cmd(data->cmd1_av[0], dir_path);
	data->cmd2_path = resolve_cmd(data->cmd2_av[0], dir_path);
	if (!data->cmd1_path || !data->cmd2_path)
		exit_all_error(data, "cmd path", 1); // might have to change this because it outputs success
	free_argv(dir_path);
}

int	init_pipex(t_pipex *data, char **av)
{	
	data->cmd1_path = NULL;
	data->cmd2_path = NULL;
	data->fd_in = -1;
	data->fd_out = -1;
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
	data->file1 = av[1];
	data->file2 = av[4];
	data->cmd1_av = NULL;
	data->cmd2_av = NULL;
	data->cmd1_av = get_cmd_argv(av[2]);
	if (!data->cmd1_av)
		exit_all_error(data, "Failed to allocate", 1);
	data->cmd2_av = get_cmd_argv(av[3]);
	if (!data->cmd2_av)
		exit_all_error(data, "Failed to allocate", 1);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;
	
	if (ac == 5)
	{
		init_pipex(&data, av);
		find_cmd_path(&data, envp);
		execute_pipex(&data, envp);
	}
	else
	{
		write(2, "Error: wrong number of arguments\n", 33);
		return (1);
	}
	free_all(&data);
	return 0;
}
// execve(data->cmd1_path, data->cmd1_av, envp);
// if (access(data->cmd1_path, F_OK) != 0)
//     exit_all_error(data, data->cmd1_av[0], 127); // file doesn't exist
// else if (access(data->cmd1_path, X_OK) != 0)
//     exit_all_error(data, data->cmd1_av[0], 126); // not executable
// else 
// 	exit_all_error(data, NULL, 1);
// waitpid(pid2, &status1, 0);
// waitpid(pid2, &status2, 0);        // capture the second child's exit status
// if (WIFEXITED(status))            // check if it exited normally
//     exit(WEXITSTATUS(status));