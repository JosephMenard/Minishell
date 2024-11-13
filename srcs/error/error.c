/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:24:56 by mianni            #+#    #+#             */
/*   Updated: 2024/11/12 09:59:12 by jmenard          ###   ########.fr       */
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

void	error_token(char *token)
{
	ft_putstr_fd("Minishell: syntax error near unexpected token '", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd("'\n", 2);
}

int	perror_r(char *error_type, char *token)
{
	ft_putstr_fd(error_type, 2);
	perror(token);
	return (-1);
}
