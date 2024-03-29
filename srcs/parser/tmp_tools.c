/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:04:37 by xle-baux          #+#    #+#             */
/*   Updated: 2022/07/28 14:01:16 by xle-baux         ###   ########.fr       */
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

void	print_token_struct(t_token *token)
{
	printf("---------------token-------------\n\n");
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
		printf("\n\n---------------cammand id = %i-------------\n", cmd->id);
		while (cmd->argv[i])
		{
			printf("%s\t\ti = %i\n", cmd->argv[i], i);
			printf("fd_in = %i\nfd_out = %i\n\n", cmd->fd_in, cmd->fd_out);
			i++;
		}
		cmd = cmd->next;
	}
}
