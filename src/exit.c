/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:21:17 by texenber          #+#    #+#             */
/*   Updated: 2025/11/11 13:10:46 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
}

void	free_argv(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free (av[i]);
		i++;
	}
	if (av)
		free (av);
}

void	close_all(t_pipex *data)
{
	if (data->pipe_fd[0] >= 0)
	{
		close(data->pipe_fd[0]);
		data->pipe_fd[0] = -1;
	}
	if (data->pipe_fd[1] >= 0)
	{
		close(data->pipe_fd[1]);
		data->pipe_fd[1] = -1;
	}
	if (data->fd_in >= 0)
	{
		close(data->fd_in);
		data->fd_in = -1;
	}
	if (data->fd_out >= 0)
	{
		close(data->fd_out);
		data->fd_out = -1;
	}
}

void	free_all(t_pipex *data)
{
	if (data->cmd_path)
		free(data->cmd_path);
	if (data->cmd1_av)
		free_argv(data->cmd1_av);
	if (data->cmd2_av)
		free_argv(data->cmd2_av);
}

void	exit_all_error(t_pipex *data, char *msg, int exit_code)
{
	if (msg)
		ft_perror(msg);
	close_all(data);
	free_all(data);
	exit(exit_code);
}
