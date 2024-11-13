/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:24:56 by mianni            #+#    #+#             */
/*   Updated: 2024/11/13 16:17:33 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// code erreur : pas de file ou dir
void	print_error(int error_type, char *incorrect_str, t_data *data)
{
	(void)error_type;
	(void)incorrect_str;
	exit_status(1, data);
	exit_now(1);
}

void	error_heredoc(char *token)
{
	ft_putstr_fd("Minishell: warning: here-document delimited by eof (wanted `",
		STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
}

void	error_token(char *token)
{
	ft_putstr_fd("Minishell: syntax error near unexpected token '", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
}

int	perror_r(char *error_type, char *token)
{
	ft_putstr_fd(error_type, STDERR_FILENO);
	perror(token);
	return (-1);
}
