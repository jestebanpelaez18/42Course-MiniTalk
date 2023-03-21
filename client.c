/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:16:40 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/03/21 15:00:53 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_to_server(char *str, int n_pid, size_t len)
{
	size_t	i;
	int		bit_counter;

	i = 0;
	while (i < len)
	{
		bit_counter = 0;
		while (bit_counter < 8)
		{
			if ((str[i] >> bit_counter) & 1)
				kill(n_pid, SIGUSR1);
			else
				kill(n_pid, SIGUSR2);
			usleep(150);
			bit_counter++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		bit_to_server(str, pid, ft_strlen(str));
		bit_to_server("\n", pid, ft_strlen("\n"));
	}
	else
		ft_printf("Just write the PID and the message as arguments \n");
}
