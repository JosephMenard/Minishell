/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:13:09 by mianni            #+#    #+#             */
/*   Updated: 2024/11/14 13:10:54 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cd(char **path, int i, t_data *data)
{
	if (!path[1])
	{
		ft_putstr_fd("Minishell: cd: No such file or directory\n", STDERR_FILENO);
		exit_status(1, data);
		return (1);
	}
	if (chdir(path[i + 1]) == -1)
	{
		exit_status(1, data);
		perror("cd");
		return (g_status = 1, 1);
	}
	exit_status(0, data);
	return (0);
}
