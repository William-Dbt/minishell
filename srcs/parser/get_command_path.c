/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:35:36 by wdebotte          #+#    #+#             */
/*   Updated: 2022/07/21 17:41:29 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_cmd_in_dir(char *cmd, char *dir_name)
{
	DIR				*fd_dir;
	struct dirent	*dir;

	if (cmd == NULL || dir_name == NULL)
		return (FALSE);
	fd_dir = opendir(dir_name);
	if (fd_dir == NULL)
		return (FALSE);
	while (1)
	{
		dir = readdir(fd_dir);
		if (dir == NULL)
			break ;
		if (_strcmp(dir->d_name, cmd) == TRUE)
		{
			closedir(fd_dir);
			return (TRUE);
		}
	}
	closedir(fd_dir);
	return (FALSE);
}

char	*get_command_path(t_infos *infos, char *cmd)
{
	int		i;
	char	**path_dir;
	char	*path_env;
	char	*buffer[2];

	buffer[0] = cmd;
	path_env = get_env_var_value(infos, "PATH");
	if (path_env == NULL)
		return (buffer[0]);
	path_dir = ft_split(path_env, ':');
	if (path_dir == NULL)
		return (NULL);
	i = -1;
	while (path_dir[++i] != NULL)
	{
		if (is_cmd_in_dir(buffer[0], path_dir[i]))
		{
			buffer[1] = fill_command_path(path_dir[i], buffer[0]);
			free_char_tab(path_dir);
			return (buffer[1]);
		}
	}
	free_char_tab(path_dir);
	return (buffer[0]);
}
