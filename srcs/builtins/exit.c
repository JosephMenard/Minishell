/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:13:04 by mianni            #+#    #+#             */
/*   Updated: 2024/11/12 16:28:24 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	to_many_args(void)
{
	ft_putstr_fd("Minishell: exit: too many arguments\n", 2);
	return ;
}

int	check_num(char *arg)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (arg[i])
	{
		if (i == 0 && arg[i] == '-')
		{
			sign = -1;
			i++;
			return (255);
		}
		if (ft_isdigit(arg[i]) == 0)
		{
			ft_putstr_fd("Minishell: exit: ", 2);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			return (2);
		}
		i++;
	}
	return (ft_atoi(arg));
}

void	ft_exit(char **args, t_data *data)
{
	int	status;
	int	i;

	i = 0;
	status = 0;
	if (!args[1])
		exit_now(data->status);
	if (args[1] && args[2] == NULL)
		exit_now(check_num(args[1]));
	if (args[2])
	{
		status = check_num(args[1]);
		if (status == 2)
			exit_now(status);
		else
		{
			exit_status(1, data);
			return (to_many_args());
		}
	}
	if (args[3])
		return (to_many_args());
}