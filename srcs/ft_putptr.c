/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:35:19 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/03/16 12:42:36 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_puthex(unsigned long n)
{
	unsigned int		count;
	char				*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += ft_puthex(n / 16);
		count += ft_puthex(n % 16);
	}
	else
		count += ft_putchari(hex[n]);
	return (count);
}

int	ft_putptr(void	*ptr)
{
	unsigned int	count;
	unsigned long	addr;

	addr = (unsigned long)ptr;
	count = 0;
	count += ft_putstri("0x");
	if (addr == 0)
		count += ft_putchari('0');
	else
		count += ft_puthex(addr);
	return (count);
}
