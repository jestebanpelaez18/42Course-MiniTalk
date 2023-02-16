/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:50:35 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/12/14 15:44:59 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	print_string(char *s)
{
	int	len_s;

	len_s = 0;
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		len_s = 6;
		return (len_s);
	}
	ft_putstr_fd(s, 1);
	len_s = ft_strlen(s);
	return (len_s);
}
