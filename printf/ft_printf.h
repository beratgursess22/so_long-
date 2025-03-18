/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrahimberatgurses <ibrahimberatgurses@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:46:00 by igurses           #+#    #+#             */
/*   Updated: 2024/11/16 19:11:36 by ibrahimbera      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_unsing(unsigned int u);
int		ft_pointer(unsigned long p);
int		ft_hex(unsigned int x, int b);

int		ft_check(char c, va_list arg);
int		ft_check2(char c, va_list arg);
int		ft_printf(const char *str, ...);

#endif
