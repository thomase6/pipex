/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:02:18 by texenber          #+#    #+#             */
/*   Updated: 2025/11/11 13:10:07 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_cmd_argv(char *av)
{
	char	**new_cmd;

	if (!av)
		return (NULL);
	new_cmd = ft_split(av, ' ');
	if (!new_cmd)
		return (NULL);
	return (new_cmd);
}

static int	init_pipex(t_pipex *data, char **av)
{
	data->cmd_path = NULL;
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
		exit_all_error(data, "Failed to allocate cmd1_av\n", 1);
	data->cmd2_av = get_cmd_argv(av[3]);
	if (!data->cmd2_av)
		exit_all_error(data, "Failed to allocate cmd2_av\n", 1);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;

	if (ac == 5)
	{
		init_pipex(&data, av);
		if (pipe(data.pipe_fd) == -1)
			exit_all_error(&data, "Pipe failed\n", 1);
		execute_pipex(&data, envp);
	}
	else
	{
		ft_perror("Error: wrong number of arguments\n");
		return (1);
	}
	free_all(&data);
	close_all(&data);
	return (0);
}
