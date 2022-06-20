/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:35:36 by wdebotte          #+#    #+#             */
/*   Updated: 2022/06/09 17:15:12 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_cmd_in_dir(char *cmd, char *dir_name, int res)
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
		if (is_cmd_in_dir(buffer[0], path_dir[i], 1))
		{
			buffer[1] = fill_command_path(path_dir[i], buffer[0]);
			free_char_tab(path_dir);
			return (buffer[1]);
		}
	}
	free_char_tab(path_dir);
	return (buffer[0]);
}

/*char	*get_cmd_name(char *line)
{
	int		n;
	int		i;
	char	*cmd;

	i = 0;
	while (line[i] != '\0' && is_whitespace(line[i]))
		i++;
	n = 0;
	while (line[i + n] != '\0' && !is_whitespace(line[i + n]))
		n++;
	cmd = malloc(sizeof(char) * (n + 1));
	if (cmd == NULL)
		return (NULL);
	n = 0;
	while (line[i] != '\0' && !is_whitespace(line[i]))
		cmd[n++] = line[i++];
	cmd[n] = '\0';
	return (cmd);
}*/