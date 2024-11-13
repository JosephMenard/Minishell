/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:54:24 by mianni            #+#    #+#             */
/*   Updated: 2024/11/11 20:03:57 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	continue_until_find(int *i, int *j, char *command_line,
		char char_to_find)
{
	++(*j);
	while (command_line[*i + *j] && command_line[*i + *j] != char_to_find)
		(*j)++;
}

int	check_quoted(char *command_line, int *i)
{
	if (command_line[*i] == '\'')
		return (11);
	if (command_line[*i] == '"')
		return (12);
	return (10);
}

t_token	*token_loop_creation(t_token *token_list, char *command_line, int *i)
{
	int		j;
	char	*str;

	j = 0;
	while (command_line[*i + j] && is_a_space(command_line[*i + j]) == false
		&& is_a_separator(command_line[*i + j]) == false)
	{
		if (command_line[*i + j] == '(')
			continue_until_find(i, &j, command_line, ')');
		else if (command_line[*i + j] == '"')
			continue_until_find(i, &j, command_line, '"');
		else if (command_line[*i + j] == '\'')
			continue_until_find(i, &j, command_line, '\'');
		j++;
	}
	if (is_a_quote(command_line[*i]) == true)
		str = ft_substr(command_line, *i + 1, j - 2, 0);
	else
		str = ft_substr(command_line, *i, j, 0);
	if (str[0] == '\0' && !is_a_quote(command_line[*i + j - 1]))
		return (*i += j, token_list);
	token_list = new_token(token_list, str, check_quoted(command_line, i));
	*i += j;
	return (token_list);
}
