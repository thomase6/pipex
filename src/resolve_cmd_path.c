/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_cmd_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:49:54 by texenber          #+#    #+#             */
/*   Updated: 2025/11/07 16:36:02 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*resolve_cmd(char *cmd, char **dir_path)
{
	int		i;
	char	*tmp;
	char	*result;

	i = -1;
	result = NULL;
	if (ft_strlen(cmd) == 0)
		return (ft_strdup(" "));
	if (ft_strchr(cmd, '/'))
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
	while (dir_path[++i])
	{
		tmp = ft_strjoin(dir_path[i], "/");
		result = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!result)
			return (NULL);
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
			break ;
		}
		i++;
	}
	if (!env_path)
		exit_all_error(data, "No such file or directory", 127);
	dir_path = ft_split(env_path, ':');
	if (!dir_path)
		exit_all_error(data, "failed to allocate dir_path", 1);
	data->cmd1_path = resolve_cmd(data->cmd1_av[0], dir_path);
	data->cmd2_path = resolve_cmd(data->cmd2_av[0], dir_path);
	if (!data->cmd1_path || !data->cmd2_path)
		exit_all_error(data, "failed to allocate cmd_path", 1);
	free_argv(dir_path);
}
