/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:35:36 by wdebotte          #+#    #+#             */
/*   Updated: 2022/05/22 13:49:58 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_cmd_in_dir(char *cmd, char *dir_name, int res)
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
		if (ft_strlen(dir->d_name) > ft_strlen(cmd))
			res = ft_strncmp(dir->d_name, cmd, ft_strlen(dir->d_name));
		else
			res = ft_strncmp(dir->d_name, cmd, ft_strlen(cmd));
		if (res == 0)
		{
			closedir(fd_dir);
			return (TRUE);
		}
	}
	closedir(fd_dir);
	return (FALSE);
}

char	*fill_command_path(char *path, char *cmd)
{
	int		i;
	int		n;
	char	*buffer;

	buffer = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(cmd) + 2));
	if (buffer == NULL)
		return (NULL);
	i = -1;
	while (path[++i] != '\0')
		buffer[i] = path[i];
	buffer[i++] = '/';
	n = i;
	i = -1;
	while (cmd[++i] != '\0')
		buffer[n + i] = cmd[i];
	buffer[n + i] = '\0';
	return (buffer);
}

void	get_cmd_name(char *line, char *cmd)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != ' ')
	{
		cmd[i] = line[i];
		i++;
	}
	cmd[i] = '\0';
}

char	*get_command_path(char *line)
{
	int		i;
	char	**path_dir;
	char	*path_env;
	char	*path;
	char	cmd[ft_strlen(line) + 1];

	get_cmd_name(line, cmd);
	path_env = getenv("PATH");
	if (path_env == NULL)
		return (ft_substr(cmd, 0, ft_strlen(cmd)));
	path_dir = ft_split(path_env, ':');
	if (path_dir == NULL)
		return (NULL);
	i = -1;
	while (path_dir[++i] != NULL)
	{
		if (is_cmd_in_dir(cmd, path_dir[i], 1))
		{
			path = fill_command_path(path_dir[i], cmd);
			free_char_tab(path_dir);
			return (path);
		}
	}
	free_char_tab(path_dir);
	return (ft_substr(cmd, 0, ft_strlen(cmd)));
}
