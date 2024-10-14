/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:51:40 by jmenard           #+#    #+#             */
/*   Updated: 2024/05/29 14:50:31 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long int	i;
	unsigned char		*b_s1;
	unsigned char		*b_s2;

	i = 0;
	b_s1 = (unsigned char *)s1;
	b_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (b_s1[i] == b_s2[i] && i < n - 1 && b_s1[i])
		i++;
	return (b_s1[i] - b_s2[i]);
}
