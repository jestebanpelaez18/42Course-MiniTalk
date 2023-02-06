/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:04:06 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/12/14 13:58:08 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_uint_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_put_uint_fd(n / 10, fd);
		ft_put_uint_fd(n % 10, fd);
	}
	if (n >= 0 && n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
}

static int	ft_uint_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	print_unsigned(unsigned int value)
{
	int	len_value;

	len_value = 0;
	if (value == 0)
	{
		ft_putchar_fd('0', 1);
		len_value += 1;
	}
	if (value > 0)
	{
		ft_put_uint_fd(value, 1);
		len_value += ft_uint_len(value);
	}
	else if (value < 0)
	{
		value = 4294967295;
		ft_put_uint_fd(value, 1);
		len_value += ft_uint_len(value);
	}
	return (len_value);
}
