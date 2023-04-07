/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:16:33 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/07 16:37:09 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*get_str(char *str, char c)
{
	char	*s2;
	size_t	i;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (s2 == NULL)
		return (0);
	i = 0;
	if(!str)
	{
		s2[i] = c;
		s2[i+1] = 0;
	}
	else
	{
		while (str[i])
		{
			s2[i] = str[i];
			i++;
		}
		s2[i] = c;
		s2[i+1] = 0;
		free(str);
	}
	return (s2);
}

void	signal_handler(int bit)
{
	static int	ch;
	static int	bit_counter;
	static char	*str;

	if (str == NULL)
		str = ft_strdup("");
	if (bit == SIGUSR1)
		ch = ch | (1 << bit_counter);
	bit_counter++;
	if (bit_counter == 8)
	{
		if (ch != 0)
			str = get_str(str, ch);
		else
		{
			ft_putendl_fd(str,1);
			free(str);
			str = NULL;			
		}
		ch = 0;
		bit_counter = 0;
	}
}

int	main(void)
{
	ft_printf("Bienvenido a mi Server \n");
	ft_printf("My server PID is: %d \n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
}
