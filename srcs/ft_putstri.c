/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:29:57 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/03/16 13:18:59 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstri(char const *s)
{
	int	i;
	int	tmp;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		i++;
	tmp = write(1, s, i);
	if (tmp < 0)
		return (-1);
	return (i);
}
