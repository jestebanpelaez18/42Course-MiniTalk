/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:16:33 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/05 16:42:41 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*get_str(char *str, char c)
{
	char	*s2;
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	s2 = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
	if (s2 == NULL)
		return (0);
	while (str[i] != '\0')
	{
		s2[i] = str[i];
		i++;
	}
	s2[i] = c;
	i++;
	s2[i] = '\0';
	return (s2);
}

void	signal_handler(int bit)
{
	static int	ch;
	static int	bit_counter;
	static char	*str;

	if (bit == SIGUSR1)
		ch = ch | (1 << bit_counter);
	bit_counter++;
	if (bit_counter == 8)
	{
		if (ch)
			str = get_str(str, ch);
		else
		{
			ft_printf("%s", str);
			ch = 0;
			bit_counter = 0;
			free(str);
		}
	}
}

int	main(void)
{
	ft_printf("Bienvenido a mi Server \n");
	ft_printf("My server PID is: %d \n", getpid());
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}
