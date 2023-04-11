/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:16:40 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/11 14:28:46 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_to_server(char *str, int n_pid, size_t len)
{
	size_t	i;
	int		bit_counter;

	i = 0;
	bit_counter = 0;
	while (i <= len)
	{
		while (bit_counter < 8)
		{
			if ((str[i] >> bit_counter) & 1)
				kill(n_pid, SIGUSR1);
			else
				kill(n_pid, SIGUSR2);
			usleep(100);
			bit_counter++;
		}
		bit_counter = 0;
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
		if (pid == 0)
		{
			ft_putendl_fd("Error", 1);
			exit(1);
		}
		str = argv[2];
		bit_to_server(str, pid, ft_strlen(str));
	}
	else
		ft_printf("Just write the PID and the message as arguments \n");
	return (0);
}
