/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:04:57 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/12/14 13:57:37 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_conversion(char type, va_list args)
{
	int	bytes_r;

	bytes_r = 0;
	if (type == 'c')
	{
		bytes_r += 1;
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if (type == 's')
		bytes_r += print_string(va_arg(args, char *));
	else if (type == 'i' || type == 'd')
		bytes_r += print_numbers(va_arg(args, int));
	else if (type == 'X' || type == 'x')
		bytes_r += print_hexadecimal(va_arg(args, unsigned int), type);
	else if (type == 'u')
		bytes_r += print_unsigned(va_arg(args, unsigned int));
	else if (type == 'p')
		bytes_r += print_pointer(va_arg(args, void *));
	else if (type == '%')
	{
		bytes_r += 1;
		ft_putchar_fd('%', 1);
	}
	return (bytes_r);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes_r;
	int		i;

	va_start(args, format);
	i = 0;
	bytes_r = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			bytes_r += check_conversion(format[i], args);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
			bytes_r += 1;
		}
	}
	va_end(args);
	return (bytes_r);
}
