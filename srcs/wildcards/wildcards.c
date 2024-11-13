/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:09:56 by jmenard           #+#    #+#             */
/*   Updated: 2024/11/12 14:20:08 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	found_file_bis(char *file, char *cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[j] && cmd[i])
	{
		if (cmd[i] == '*' && file[0] != '.')
			return (0);
		if (file[j] != cmd[i] || file[0] == '.')
			return (1);
		i++;
		j++;
	}
	return (0);
}

int	found_file_biss(int i, char *file, char *cmd)
{
	int	k;

	k = ft_strlen(file);
	while (k != 0 && file[k] != cmd[i])
		k--;
	return (k);
}

int	found_files(char *file, char *cmd)
{
	int	i;
	int	j;
	int	u;

	i = 0;
	j = 0;
	u = ft_strlen(cmd);
	file = remove_star(file);
	if (cmd[u - 1] == '*')
		return (found_file_bis(file, cmd));
	while (file[j])
	{
		if (cmd[i] == '*')
		{
			i++;
			j = found_file_biss(i, file, cmd);
		}
		if (cmd[i] != file[j])
			return (1);
		i++;
		j++;
	}
	if ((cmd[i] != '\0' && file[j] == '\0') || file[0] == '.')
		return (1);
	return (0);
}

bool	checking_token_bis(t_token **token_list)
{
	t_token	*token;

	token = *token_list;
	while (token)
	{
		if (is_operator_bis(token))
		{
			if (is_operator_bis(token->prev))
				return (error_token(token->token), false);
		}
		token = token->next;
	}
	return (true);
}

char	**copy_remaining_cmd(char **cmd, char **new_cmd, int *i, int *c)
{
	new_cmd[*i] = cmd[*c];
	(*i)++;
	(*c)++;
	return (new_cmd);
}