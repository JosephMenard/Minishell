/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:59:13 by jmenard           #+#    #+#             */
/*   Updated: 2024/10/14 14:27:29 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t nmemb, size_t size)
{
	void			*str;
	static t_trash	*trash = NULL;

	if (nmemb * size > __SIZE_MAX__ || nmemb * size == 0)
		safe_exit(trash);
	str = malloc(nmemb * size);
	if (!str)
		safe_exit(trash);
	ft_lstadd_front(&trash, ft_lstnew(str));
	return ((void *)(str));
}
