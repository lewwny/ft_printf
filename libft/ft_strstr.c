/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:42:35 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/03/08 11:04:14 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	size = ft_strlen(needle);
	i = 0;
	if (*needle == '\0')
		return ((char *) haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[j + i] == needle[j] && needle[j] && haystack[j + i])
		{
			j++;
			if (j == size)
				return ((char *) &haystack[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	printf("%s", ft_strstr(argv[1], argv[2]));
	return (0);
}*/
