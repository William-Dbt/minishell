/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:42:36 by wdebotte          #+#    #+#             */
/*   Updated: 2022/06/30 18:46:16 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipes(char *error, int **pfds, int idx_pipes, int idx_tab)
{
	int	i;

	i = -1;
	while (++i < idx_pipes)
	{
		if (close(pfds[i][0]) < 0)
			ft_putstr_fd(SH_NAME": close_pipes: close error\n", 2);
		if (close(pfds[i][1]) < 0)
			ft_putstr_fd(SH_NAME": close_pipes: close error\n", 2);
	}
	if (idx_tab > 0)
	{
		i = 0;
		while (i < idx_tab)
			free(pfds[i++]);
		free(pfds);
	}
	if (error != NULL)
		ft_putstr_fd(error, 2);
}

int	**init_pipefds(int npipes)
{
	int	i;
	int	**pfds;

	pfds = (int **)malloc(sizeof(int *) * npipes);
	if (pfds == NULL)
	{
		ft_putstr_fd(SH_NAME": pipefds: malloc error\n", 2);
		return (NULL);
	}
	i = -1;
	while (++i < npipes)
	{
		pfds[i] = (int *)malloc(sizeof(int) * 2);
		if (pfds[i] == NULL)
		{
			close_pipes(SH_NAME": pipefds: malloc error\n", pfds, i - 1, i - 1);
			return (NULL);
		}
		if (pipe(pfds[i]) < 0)
		{
			close_pipes(SH_NAME": pipefds: pipe error\n", pfds, i - 1, i);
			return (NULL);
		}
	}
	return (pfds);
}

void	retwait_pids(t_infos *infos, int *pids)
{
	int	i;
	int	wstatus;

	i = -1;
	while (++i < infos->npipes + 1)
		waitpid(pids[i], &wstatus, 0);
	if (WIFEXITED(wstatus))
		infos->wstatus = WEXITSTATUS(wstatus);
}