/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:17:00 by jmenard           #+#    #+#             */
/*   Updated: 2024/10/13 16:55:26 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	// t_list	*new_elem;
	// t_list	*new_lst;
	// void	*new_f;

	// new_lst = NULL;
	// if (!lst || !f)
	// 	return (NULL);
	// while (lst)
	// {
	// 	new_f = f(lst->content);
	// 	new_elem = ft_lstnew(new_f);
	// 	if (!new_elem)
	// 	{
	// 		del(new_f);
	// 		ft_lstclear(&new_lst, del);
	// 		return (NULL);
	// 	}
	// 	ft_lstadd_back(&new_lst, new_elem);
	// 	lst = lst->next;
	// }
	// return (new_lst);
	(void)lst;
	(void)f;
	(void)del;
	return (NULL);
}
