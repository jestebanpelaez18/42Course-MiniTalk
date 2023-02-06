/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:27:17 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/12/14 15:44:43 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit_len(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	print_numbers(int n)
{
	int	len_n;

	len_n = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		len_n += 1;
	}
	else if (n != 0)
	{
		ft_putnbr_fd(n, 1);
		len_n += ft_digit_len(n);
	}
	return (len_n);
}
