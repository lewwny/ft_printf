/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:59:42 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/03/16 12:40:26 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_putstri(char const *s);
int		ft_putchari(char c);
int		ft_putnbri(int n);
int		ft_printf(const char *format, ...);
int		ft_putnbrui(unsigned int n);
int		ft_putnbrhexmin(int n);
int		ft_putnbrhexmaj(int n);
int		ft_putptr(void	*ptr);

#endif
