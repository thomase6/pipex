/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:21:17 by texenber          #+#    #+#             */
/*   Updated: 2025/11/03 11:24:36 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

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

void	free_all(t_pipex *data)
{
	if (data->cmd1_path)
		free(data->cmd1_path);
	if (data->cmd2_path)
		free(data->cmd2_path);
	if (data->cmd1_av)
		free_argv(data->cmd1_av);
	if (data->cmd2_av)
		free_argv(data->cmd2_av);
	if (data->fd_in >= 0)
		close(data->fd_in);
	if (data->fd_out >= 0)
		close(data->fd_out);
	if (data->pipe_fd[0] >= 0)
		close(data->pipe_fd[0]);
	if (data->pipe_fd[1] >= 0)
		close(data->pipe_fd[1]);
	
	
}

void	exit_all_error(t_pipex *data, const char *msg, int exit_code)
{
	if (msg)
		perror(msg);
	free_all(data);
	exit(exit_code);
}

void	perror_exit(const char *err_msg, int exit_code)
{
	perror(err_msg);
	exit(exit_code);
}
