/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:16:33 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/02/09 18:32:16 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int bit)
{
	static int	ch;
	static int	bit_counter;

	if (bit == SIGUSR1)
	{
		ch = ch | (1 << bit_counter);
	}
	bit_counter++;
	if (bit == 8)
	{
		ft_printf("%c", ch);
		ch = 0;
		bit_counter = 0;
	}
}

int	main(void)
{
	ft_printf("Bienevenido a mi Server");
	ft_printf("My server PID is: %d", getpid());
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}
