/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:29:22 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/03/16 11:37:24 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbri(int n)
{
	unsigned int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putchari('-');
		count += ft_putchari('2');
		n = 147483648;
	}
	if (n < 0)
	{
		count += ft_putchari('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		count += ft_putnbri(n / 10);
		count += ft_putnbri(n % 10);
	}
	else
		count += ft_putchari(n + 48);
	return (count);
}
