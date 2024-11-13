/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:13:26 by mianni            #+#    #+#             */
/*   Updated: 2024/11/12 15:58:28 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(char **command)
{
	t_env	*env;

	if (!command[1])
		return ;
	env = get_env(NULL);
	while (env)
	{
		if (ft_strcmp(env->name, command[1]) == 0)
		{
			env->content = "$";
			env->name = "$";
		}
		env = env->next;
	}
}
