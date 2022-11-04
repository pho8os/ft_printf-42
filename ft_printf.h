/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:03:41 by absaid            #+#    #+#             */
/*   Updated: 2022/11/02 15:10:38 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define B16L "0123456789abcdef"
# define B16U "0123456789ABCDEF"
# define B10 "0123456789"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *fmt, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_strlen(const char *s);
int	ft_display_base_s(long long n, char *base);
int	ft_display_base_u(unsigned long long n, char *base);

#endif
