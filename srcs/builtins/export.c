/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:13:20 by mianni            #+#    #+#             */
/*   Updated: 2024/11/14 11:47:08 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	search_var(char *str_name, char *str_content, t_env *env)
{
	while (env)
	{
		if (ft_strcmp(env->name, str_name) == 0)
			return (env->content = str_content, true);
		env = env->next;
	}
	return (false);
}

char	*try_to_expand(char *str, int index)
{
	int		len;
	int		start;
	char	*str_bis;
	t_env	*env;

	len = 0;
	start = index + 1;
	env = get_env(NULL);
	while (str[index])
	{
		index++;
		len++;
	}
	str_bis = ft_substr(str, start, len, 0);
	while (env)
	{
		if (ft_strcmp(env->name, str_bis) == 0)
		{
			str_bis = ft_substr(env->content, 0, ft_strlen(env->content), 1);
			return (str_bis);
		}
		env = env->next;
	}
	return (str);
}

int	find_sign2(char **command_line, char *str_content, int *i, int *j)
{
	char	*str_name;
	int		len;
	t_env	*env;
	t_data	*data;

	str_name = NULL;
	data = get_data(NULL);
	env = get_env(NULL);
	len = ft_strlen(command_line[*i]);
	str_name = ft_substr(command_line[*i], 0, *j, 1);
	if (command_line[*i][*j + 1] == '$')
		str_content = try_to_expand(command_line[*i], *j + 1);
	else
	{
		str_content = ft_substr(command_line[*i], *j + 1, len, 1);
		if (search_var(str_name, str_content, env) == true)
			return (0);
	}
	if (!str_name)
		exit_status(1, data);
	new_node(env, str_name, str_content);
	return (1);
}

void	find_sign(char **command_line, int i, t_data *data)
{
	int		j;
	t_env	*env;
	int		len;

	env = get_env(NULL);
	j = 0;
	while (command_line[i][j])
	{
		len = ft_strlen(command_line[i]);
		if (command_line[i][j] != '=' && ft_isalnum(command_line[i][j]) == 0)
		{
			ft_putstr_fd("incorrect pattern for export: '", STDERR_FILENO);
			ft_putstr_fd(command_line[i], STDERR_FILENO);
			ft_putstr_fd("'\n", STDERR_FILENO);
			exit_status(2, data);
			return ;
		}
		if (command_line[i][j] == '=')
		{
			if (find_sign2(command_line, NULL, &i, &j) == 0)
				return (exit_status(0, data));
			break ;
		}
		j++;
	}
}

void	ft_export(char **command_line, t_data *data)
{
	int		i;
	t_env	*env;

	i = 1;
	env = get_env(NULL);
	if (!command_line[1])
		ft_env_export(data);
	while (command_line[i])
	{
		find_sign(command_line, i, data);
		i++;
	}
	exit_status(0, data);
}
