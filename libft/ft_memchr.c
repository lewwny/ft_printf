/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:32:21 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/03/08 11:36:47 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	ch;
	unsigned int	i;

	ch = (char) c;
	d = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (d[i] == ch)
			return ((void *) &d[i]);
		i++;
	}
	return (NULL);
}
