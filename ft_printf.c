/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:20:13 by absaid            #+#    #+#             */
/*   Updated: 2022/11/04 14:41:48 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(va_list *ptr, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(*ptr, int));
	if (c == 'd' || c == 'i')
		len += ft_display_base_s(va_arg(*ptr, int), B10);
	if (c == 'x')
		len += ft_display_base_u(va_arg(*ptr, unsigned int), B16L);
	if (c == 'X')
		len += ft_display_base_u(va_arg(*ptr, unsigned int), B16U);
	if (c == '%')
		len += ft_putchar(c);
	if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_display_base_u(va_arg(*ptr, unsigned long int), B16L);
	}
	if (c == 's')
		len += ft_putstr(va_arg(*ptr, char *));
	if (c == 'u')
		len += ft_display_base_u(va_arg(*ptr, unsigned int), B10);
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ptr;
	int		len;
	int		i;

	i = -1;
	len = 0;
	va_start(ptr, fmt);
	while (fmt[++i])
	{
		if (fmt[i] != '%')
		{	
			len += write(1, &fmt[i], 1);
			if (len < 0)
				return (-1);
		}
		if (fmt[i] == '%' && fmt[i + 1])
		{
			len += check(&ptr, fmt[i + 1]);
			if (len < 0)
				return (-1);
			i++;
		}
	}
	return (va_end(ptr), len);
}
