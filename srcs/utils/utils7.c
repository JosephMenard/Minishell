/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:53:53 by jmenard           #+#    #+#             */
/*   Updated: 2024/11/14 11:54:46 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	search_in_env(t_env *env, t_data *data)
{
	while (env)
	{
		if (env->name && env->name[0] == '?' && !env->name[1])
		{
			env->content = ft_itoa(data->status);
			return (true);
		}
		env = env->next;
	}
	return (false);
}

bool    check_parenthesis(char *str)
{
    int    i;
    int    parenthesis;

    i = 0;
    parenthesis = 0;
    while (str[i])
    {
        if (str[i] == '(')
            parenthesis++;
        if (str[i] == ')')
            parenthesis--;
        i++;
    }
    if (parenthesis == 0)
        return (true);
    else
        return (false);
}
