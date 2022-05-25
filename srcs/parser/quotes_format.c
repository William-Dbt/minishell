/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:56:18 by xle-baux          #+#    #+#             */
/*   Updated: 2022/05/25 16:02:45 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_quotes(t_token *token)
{
	int open_quote;

	open_quote = -1;
	while (token->next)
	{
		if (token->type == QUOTE || token->type == D_QUOTE)
		{
			open_quote = token->type;
			token = token->next;
			while (token->next && token->type != open_quote)
			{
				token->type = WORD;
				token = token->next;
			}
			if (!token->next)
				return (1);
		}
		token = token->next;
	}
	return (0);
}

int clean_quotes(t_token *token)
{
/* 	int		open_quote;
	t_token *tmp; */

	if (check_quotes(token))
		return (1);
/* 	open_quote = -1;
	while (token->next)
	{
		if (token->type == QUOTE || token->type == D_QUOTE)
		{
			open_quote = token->type;
		}
	} */
	return (0);
	
}


/* {
	t_token *tmp;

	while (token->next)
	{
		if (token->type == DOLLAR)
		{
			tmp = token->next->next;
			token->content = getenv(token->next->content);
			token->type = WORD;
			free(token->next);
			token->next = tmp;
		}
		token = token->next;
	}
} */