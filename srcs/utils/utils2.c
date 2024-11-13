/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:38:28 by mianni            #+#    #+#             */
/*   Updated: 2024/11/11 19:56:52 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	separator_in_word(char *command_line, int i)
{
	int	sep;
	int	len;

	sep = 0;
	len = 0;
	while ((command_line[i] != 32 && command_line[i] != '\t')
		&& command_line[i])
	{
		if (is_a_separator(command_line[i]) == true)
			sep++;
		i++;
		len++;
	}
	if (sep != len && sep != 0)
		return (true);
	return (false);
}

bool	variable_test(char *str)
{
	int	i;

	i = 1;
	if (!str[1])
		return (true);
	if (str[1] == '?' && !str[2])
		return (true);
	if (ft_isalnum(str[1]) == 0 && str[1] != '?')
		return (false);
	i++;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

// bool		check_token_list(t_token *token_list)
//{
//	while (token_list)
//	{
//		if (token_list->type == -1)
//			return (print_error(1, token_list->token, data), false);
//		token_list = token_list->next;
//	}
//	return (true);
//}

bool	is_a_quote(char c)
{
	if (c == '"' || c == '\'')
		return (true);
	return (false);
}

void	print_env(t_env *env, int flag)
{
	if (flag == 1)
	{
		while (env)
		{
			printf("%s %s=\"%s\"\n", "export", env->name, env->content);
			env = env->next;
		}
	}
	else
	{
		while (env)
		{
			printf("%s=\"%s\"\n", env->name, env->content);
			env = env->next;
		}
	}
}
