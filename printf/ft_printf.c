/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrahimberatgurses <ibrahimberatgurses@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:06:53 by igurses           #+#    #+#             */
/*   Updated: 2024/11/16 19:02:26 by ibrahimbera      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list arg)
{
	int	a;

	a = 0;
	if (c == 'c')
		a += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		a += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		a += ft_check2(c, arg);
	else if (c == 'd' || c == 'i')
		a += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		a += ft_unsing(va_arg(arg, unsigned int));
	else if (c == 'x')
		a += ft_hex(va_arg(arg, unsigned int), 0);
	else if (c == 'X')
		a += ft_hex(va_arg(arg, unsigned int), 1);
	else if (c == '%')
		a += ft_putchar('%');
	else
	{
		a += ft_putchar('%');
		a += ft_putchar(c);
	}
	return (a);
}

int	ft_check2(char c, va_list arg)
{
	unsigned long	ptr;
	int				a;

	a = 0;
	if (c == 'p')
	{
		ptr = va_arg(arg, unsigned long);
		if (ptr == (unsigned long) NULL)
			a += ft_putstr("(nil)");
		else
		{
			a += ft_putstr("0x");
			a += ft_pointer(ptr);
		}
	}
	return (a);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		check;

	va_start(arg, str);
	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			check++;
		}
		if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ' && str[i])
				i++;
			check += ft_check(str[i], arg);
		}
		i++;
	}
	va_end(arg);
	return (check);
}
