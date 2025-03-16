/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:21:56 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/03/09 14:48:13 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copystring(char const *s, int start, int end)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *) malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	while (start < end)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

static void	machination(int *i, char const *s, char c, int *debut)
{
	while (s[*i] == c)
		(*i)++;
	*debut = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
}

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;
	char	*tmp;
	int		debut;

	i = 0;
	j = 0;
	res = (char **) malloc(sizeof(char *) * ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (s[i])
	{
		machination(&i, s, c, &debut);
		if (i > debut)
		{
			tmp = copystring(s, debut, i);
			res[j++] = tmp;
		}
	}
	res[j] = NULL;
	return (res);
}
