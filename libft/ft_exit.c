/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:44:13 by jmenard           #+#    #+#             */
/*   Updated: 2024/10/14 14:21:42 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	exit_now(void)
{
	ft_malloc(0, 0);
}

void	safe_exit(t_trash *trash)
{
	ft_lstclear(&trash, ft_del);
	printf("EXIT !!\n");
	exit (0);
}

void	ft_del(void	*content)
{
	free(content);
	content = NULL;
}
