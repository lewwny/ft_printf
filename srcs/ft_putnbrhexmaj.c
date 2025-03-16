/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexmaj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:49:00 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/03/16 12:21:09 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbrhexmaj(int n)
{
	unsigned int		count;
	unsigned int		nb;
	char				*hex;

	hex = "0123456789ABCDEF";
	count = 0;
	if (n < 0)
		nb = 4294967295 + n + 1;
	else
		nb = n;
	if (nb >= 16)
	{
		count += ft_putnbrhexmaj(nb / 16);
		count += ft_putnbrhexmaj(nb % 16);
	}
	else
		count += ft_putchari(hex[nb]);
	return (count);
}
/*
int	main(void)
{
	ft_putnbrhexmin(322006);
}*/
