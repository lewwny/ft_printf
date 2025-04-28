/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:57:11 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/04/28 08:15:36 by lengarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_process(char conv, va_list *args)
{
	int	count;

	count = 0;
	if (conv == 'd' || conv == 'i')
		count += ft_putnbri(va_arg(*args, int));
	else if (conv == 's')
		count += ft_putstri(va_arg(*args, char *));
	else if (conv == 'c')
		count += ft_putchari(va_arg(*args, int));
	else if (conv == 'u')
		count += ft_putnbrui(va_arg(*args, unsigned int));
	else if (conv == '%')
		count += ft_putchari('%');
	else if (conv == 'x')
		count += ft_putnbrhexmin(va_arg(*args, int));
	else if (conv == 'X')
		count += ft_putnbrhexmaj(va_arg(*args, int));
	else if (conv == 'p')
		count += ft_putptr(va_arg(*args, void *));
	else
		count += ft_putchari(conv);
	return (count);
}

static int	vprintf_loop(const char *format, va_list *args)
{
	unsigned int	count;
	unsigned int	tmp;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			tmp = ft_process(*format, args);
		}
		else
			tmp = ft_putchari(*format);
		if (tmp < 0)
			return (-1);
		count += tmp;
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = vprintf_loop(format, &args);
	va_end(args);
	return (ret);
}
