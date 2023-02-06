/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:38:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/12/14 13:54:39 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	change_to_hex(unsigned int arg, char type)
{
	int		rest;
	char	str[25];
	int		i;

	i = 0;
	while (arg != 0)
	{
		rest = arg % 16;
		if (rest < 10)
			str[i] = rest + 48;
		else
		{
			if (type == 'X')
				str[i] = rest + 55;
			else
				str[i] = rest + 87;
		}
		arg = arg / 16;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar_fd(str[i--], 1);
}

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	print_hexadecimal(unsigned int arg, char type)
{
	int	len;

	len = 0;
	if (arg == 0)
	{
		ft_putchar_fd('0', 1);
		len += 1;
	}
	else
	{
		change_to_hex(arg, type);
		len = ft_hex_len(arg);
	}
	return (len);
}
