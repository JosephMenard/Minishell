/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:26:49 by jmenard           #+#    #+#             */
/*   Updated: 2024/05/29 14:51:03 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned long int		j;
	char					*new_str;

	j = 0;
	if (start >= (unsigned long int)ft_strlen((s)))
	{
		new_str = (char *)malloc(1 * sizeof(char));
		if (!new_str)
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	if (len > (unsigned long int)ft_strlen(s) - start)
		len = (unsigned long int)ft_strlen(s) - start;
	new_str = (char *)malloc(len + 1 * sizeof(char));
	if (!new_str)
		return (NULL);
	while (j < len && s[start + j])
	{
		new_str[j] = s[start + j];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}
