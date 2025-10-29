/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:02:18 by texenber          #+#    #+#             */
/*   Updated: 2025/10/29 12:33:45 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_exit(const char *err_msg, int exit_code)
{
	perror(err_msg);
	exit(exit_code);
}
void free_argv(char **av)
{
	int	i;
	
	i = 0;
	while (av[i])
	{
		free (av[i]);
		i++;
	}
	free (av);
}
void	execute_pipex(t_pipex *data, char ** envp)
{
	pid_t	pid1;
	pid_t	pid2;
	// create a pipe
	if	(pipe(data->pipe_fd) == -1)
		perror_exit("pipe", 1);
	// open the infile/outfile
	data->fd_in = open(data->file1, O_RDONLY);
	if (data->fd_in < 0)
	{
		close (data->pipe_fd[0]);
		close (data->pipe_fd[1]);
		perror_exit("failed to open file1", 1);
	} 
	data->fd_out = open(data->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fd_out < 0)
	{
		close (data->pipe_fd[0]);
		close (data->pipe_fd[1]);
		close (data->fd_in);
		perror_exit("failed to open file2", 1);
	}
	// fork the two child processes
	pid1 = fork();
	if (pid1 < 0)
	{
		close (data->pipe_fd[0]);
		close (data->pipe_fd[1]);
		close (data->fd_in);
		close (data->fd_out);
		perror_exit("fork for child 1 failed", 1);		
	}
	if (pid1 == 0)
	{
		dup2(data->fd_in, STDIN_FILENO);
		dup2(data->pipe_fd[1], STDOUT_FILENO);
		close(data->pipe_fd[0]);
		close(data->pipe_fd[1]);
		close(data->fd_in);
		close(data->fd_out);
		execve(data->cmd1_path, data->cmd1_av, envp);
		perror_exit("execve failed", 127);
	}
	
	pid2 = fork();
	if (pid2 < 0)
	{
		close (data->pipe_fd[0]);
		close (data->pipe_fd[1]);
		close (data->fd_in);
		close (data->fd_out);
		perror_exit("fork for child 2 failed", 1);		
	}
	if (pid2 == 0)
	{
		dup2(data->pipe_fd[0], STDIN_FILENO);
		dup2(data->fd_out, STDOUT_FILENO);
		close(data->pipe_fd[0]);
		close(data->pipe_fd[1]);
		close(data->fd_in);
		close(data->fd_out);
		execve(data->cmd2_path, data->cmd2_av, envp);
		perror_exit("execve failed", 127);
	}
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	close(data->fd_in);
	close(data->fd_out);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
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

	i = 0;
	result = NULL;
	if (ft_strchr(cmd, '/'))
	{
		if(access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else	
			return (NULL);
	}
	while (dir_path[i])
	{
		tmp = ft_strjoin(dir_path[i], "/");//might have to add a null check here
		result = ft_strjoin(tmp, cmd);// needs a null check because access can't take a null
		free(tmp);
		if (access(result, X_OK) == 0)
			return (result);
		free (result);
		i++;
	}
	return (NULL);
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
	{
		free_argv(data->cmd1_av);
		free_argv(data->cmd2_av);
		perror_exit("PATH not found", 1);
	}
	dir_path = ft_split(env_path, ':');
	if (!dir_path)
	{
		free_argv(data->cmd1_av);
		free_argv(data->cmd2_av);
		perror_exit("failed to split PATH", 1);
	}
	data->cmd1_path = resolve_cmd(data->cmd1_av[0], dir_path);
	if (!data->cmd1_path)
	{
		free_argv(data->cmd1_av);
		free_argv(data->cmd2_av);
		free_argv(dir_path);
		perror_exit("command not found", 127); //have to fix the message I get from this 
	}
	data->cmd2_path = resolve_cmd(data->cmd2_av[0], dir_path);
	if (!data->cmd2_path)
	{
		free(data->cmd1_path);
		free_argv(data->cmd1_av);
		free_argv(data->cmd2_av);
		free_argv(dir_path);
		perror_exit("command not found", 127);  //have to fix the message I get from this 
	}
	free_argv(dir_path);
}

int	init_pipex(t_pipex *data, char **av)
{	
	data->file1 = av[1];
	data->file2 = av[4];	
	data->cmd1_av = get_cmd_argv(av[2]);
	if (!data->cmd1_av)
		perror_exit("failed to allocate cmd1", 1);
	data->cmd2_av = get_cmd_argv(av[3]);
	if (!data->cmd2_av)
	{
		free_argv(data->cmd1_av);
		perror_exit("failed to allocate cmd2", 1);
	}
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
	free_argv(data.cmd1_av);
	free_argv(data.cmd2_av);
	free(data.cmd1_path);
	free(data.cmd2_path);
	return 0;
}
