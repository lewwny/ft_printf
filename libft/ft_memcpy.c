/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:28:29 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/03/07 11:42:50 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (!dst && !src)
		return (NULL);
	tmp1 = (unsigned char *) dst;
	tmp2 = (unsigned char *) src;
	while (n > 0)
	{
		*tmp1++ = *tmp2++;
		n--;
	}
	return (dst);
}
