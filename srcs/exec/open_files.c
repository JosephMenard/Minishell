/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:35:11 by jmenard           #+#    #+#             */
/*   Updated: 2024/11/13 13:59:58 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Code operateur : 1 = '<' / 2 = '>' / 3 = '<<' / 4 = '>>'

int	open_files(t_cmd *cmd)
{
	int	dup_status;

	dup_status = 0;
	while (cmd->files)
	{
		if (cmd->files->type == 1)
			cmd->files->fd = ft_open(cmd->files->files_name, O_RDONLY, -2);
		else if (cmd->files->type == 2)
			cmd->files->fd = ft_open(cmd->files->files_name,
					O_TRUNC | O_WRONLY | O_CREAT, -2);
		else if (cmd->files->type == 4)
			cmd->files->fd = ft_open(cmd->files->files_name,
					O_WRONLY | O_APPEND | O_CREAT, -2);
		if (cmd->files->fd == -1)
			return (perror_r("Minishell: ", cmd->files->files_name));
		else if (cmd->files->type == 1 || cmd->files->type == 3)
			dup_status = dup2(cmd->files->fd, STDIN_FILENO);
		else if (cmd->files->type == 2 || cmd->files->type == 4)
			dup_status = dup2(cmd->files->fd, STDOUT_FILENO);
		if (dup_status == -1)
			return (perror_r("Minishell: dup2 failed: ",
					cmd->files->files_name));
		cmd->files = cmd->files->next;
	}
	return (close_fds(), 0);
}

void	open_all_heredoc(t_cmd **cmd_list)
{
	t_cmd	*cmd;
	t_files	*file_temp;
	t_files	*files;

	cmd = *cmd_list;
	file_temp = cmd->files;
	while (cmd)
	{
		files = cmd->files;
		while (files)
		{
			if (files->type == 3)
				files->fd = open_heredoc(files);
			if (files->fd == -1)
				return ;
			files = files->next;
		}
		cmd = cmd->next;
	}
	(*cmd_list)->files = file_temp;
}

int	open_heredoc(t_files *files)
{
	char	*str;
	int		fd[2];

	str = ft_malloc(1, sizeof(char), 0, 0);
	if (!str)
		exit_now(1);
	str[0] = '\0';
	pipe(fd);
	ft_open(NULL, 0, fd[0]);
	while (1)
	{
		str = readline("heredoc>");
		if (!str)
			error_heredoc(files->files_name);
		if (!str || ft_strncmp(str, files->files_name,
				ft_strlen(files->files_name)) == 0)
			break ;	
		if (g_status != 0)
			return (close(fd[1]), 1);
		ft_putendl_fd(str, fd[1]);
		free(str);
	}
	return (close(fd[1]), fd[0]);
}
