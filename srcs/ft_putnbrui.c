/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:43:08 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/03/16 11:44:28 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbrui(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbrui(n / 10);
		count += ft_putnbrui(n % 10);
	}
	else
		count += ft_putchari(n + 48);
	return (count);
}
