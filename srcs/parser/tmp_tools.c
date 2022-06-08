/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:04:37 by xle-baux          #+#    #+#             */
/*   Updated: 2022/06/08 12:23:00 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*token_type_print_2(int id)
{
	if (id == 7)
		return ("D_GREAT");
	else if (id == 8)
		return ("LESS");
	else if (id == 9)
		return ("D_LESS");
	else if (id == 10)
		return ("PIPE");
	else if (id == 11)
		return ("DOLLAR");
	else if (id == 12)
		return ("BACKSLASH");
	return (NULL);
}

char	*token_type_print(int id)
{
	if (id <= 6)
	{
		if (id == 0)
			return ("NULL");
		else if (id == 1)
			return ("WORD");
		else if (id == 2)
			return ("QUOTE");
		else if (id == 3)
			return ("D_QUOTE");
		else if (id == 4)
			return ("NLINE");
		else if (id == 5)
			return ("WHITE_SPACE");
		else if (id == 6)
			return ("GREAT");
	}
	else
		return (token_type_print_2(id));
	return (NULL);
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	tmp = cmd;
	while (tmp)
	{
		i = 0;
		while (cmd->args[i])
			free(cmd->args[i++]);
		free(cmd->args);
		tmp = tmp->next;
		free(cmd);
		cmd = tmp;
	}
	free(cmd);
}

void	print_token_struct(t_token *token)
{
	printf("\n\n---------------token-------------\n\n");
	while (token->next)
	{
		ft_printf("%s\n%s\n\n", token->content, token_type_print(token->type));
		token = token->next;
	}
}

void	print_cmd_struct(t_cmd *cmd)
{
	int	n;
	int	i;

	n = 0;
	while (cmd)
	{
		i = 0;
		printf("\n\n---------------cammand %i-------------\n\n", n++);
		while (cmd->args[i])
		{
			printf("%s\t\ti = %i\n", cmd->args[i], i);
			i++;
		}
		cmd = cmd->next;
	}
}
