/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:14:26 by jmenard           #+#    #+#             */
/*   Updated: 2024/05/29 22:02:41 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}	

int	ft_str_sub_len(char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == charset)
			i++;
		while (str[i] && str[i] != charset)
		{
			if (str[i + 1] == '\0')
				return (count + 1);
			count++;
			i++;
		}
		if (str[i] == charset)
			break ;
		i++;
	}
	return (count);
}

int	ft_count_split(char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == charset)
			i++;
		if (!str[i])
			break ;
		while (str[i] && str[i] != charset)
			i++;
		count++;
	}
	return (count);
}

char	*ft_split_strs(char *str, char charset)
{
	int		i;
	int		strlen;
	char	*sous_str;

	i = 0;
	strlen = ft_str_sub_len(str, charset);
	sous_str = malloc((strlen + 1) * sizeof(char));
	if (!sous_str)
		return (NULL);
	while (i < strlen)
	{
		sous_str[i] = str[i];
		i++;
	}
	sous_str[i] = '\0';
	return (sous_str);
}

char	**ft_split(char *str, char charset)
{
	char	**final_str;
	int		i;
	int		c;
	int		nbrwords;

	i = 0;
	c = 0;
	nbrwords = ft_count_split(str, charset);
	final_str = malloc((nbrwords + 1) * sizeof(char *));
	if (!final_str)
		return (NULL);
	while (c < nbrwords)
	{
		while (str[i] == charset)
			i++;
		final_str[c] = ft_split_strs(&str[i], charset);
		if (final_str[c] == NULL)
			return (ft_free_all(final_str));
		c++;
		i = i + ft_str_sub_len(&str[i], charset);
	}
	final_str[c] = NULL;
	return (final_str);
}
