/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:54:03 by wdebotte          #+#    #+#             */
/*   Updated: 2022/05/20 15:16:04 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*line;
	char	*cmd_path;
	char	**cmd_args;

	while (1)
	{
		line = readline(">$ ");
		cmd_path = get_command_path(line);
		cmd_args = get_command_args(line, cmd_path);
		exec_simple(cmd_path, cmd_args);
		free_char_tab(cmd_args);
		free(cmd_path);
		free(line);
		line = NULL;
	}
	return (0);
}
