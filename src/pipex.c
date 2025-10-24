/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:02:18 by texenber          #+#    #+#             */
/*   Updated: 2025/10/24 16:07:57 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_pipex(t_pipex *data, char **av, char **envp)
{
	(void)envp; //this is only for test purposes
	data->file1 = av[1];
	data->cmd1_str = av[2];
	data->cmd2_str = av[3];
	data->file2 = av[4];	
	
	// I just have to open the file to be able to check if it'sa  file, I don't have to use access or anything else
	data->fd_in = open(data->file1, O_RDONLY);
	if (data->fd_in < 0)
		perror(data->file1);
	data->fd_out = open(data->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fd_out < 0)
		perror(data->file2);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;
	
	if (ac == 5)
	{
		init_pipex(&data, av, envp);
	}
	else
	{
		write(2, "Error: wrong number of arguments\n", 33);
		return (1);
	}
	return 0;
}
