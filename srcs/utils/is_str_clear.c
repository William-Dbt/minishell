/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:03:30 by wdebotte          #+#    #+#             */
/*   Updated: 2022/05/26 10:04:49 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_str_clear(char *str)
{
	while (*str != '\0')
		if (!is_whitespace(*str++))
			return (FALSE);
	return (TRUE);
}
