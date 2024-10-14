/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:14:14 by jmenard           #+#    #+#             */
/*   Updated: 2024/10/13 17:46:52 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_trash	*ft_lstnew(void *content)
{
	t_trash	*list_content;

	list_content = malloc(sizeof(struct trash_collector));
	if (!list_content)
		return (NULL);
	list_content->alloc = content;
	list_content->lock = 0;
	list_content->next = NULL;
	return (list_content);
}
