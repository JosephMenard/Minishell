/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:13:09 by mianni            #+#    #+#             */
/*   Updated: 2024/11/12 11:29:17 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cd(char **path, int i, t_data *data)
{
	if (chdir(path[i + 1]) == -1)
	{
		exit_status(1, data);
		perror("cd");
		return (data->status = 1, 1);
	}
	exit_status(0, data);
	return (0);
}
