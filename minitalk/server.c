/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-20 11:15:10 by selango           #+#    #+#             */
/*   Updated: 2024-08-20 11:15:10 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_to_char(int sig)
{
	int			bit;
	static int	c;
	static int	i;

	if (sig == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	c += ((bit & 1) << i);
	i++;
	if (i == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Welcome to SERVER\n");
	ft_printf("SERVER PID IS: %d\n", pid);
	while (1)
	{
		signal(SIGUSR2, bit_to_char);
		signal(SIGUSR1, bit_to_char);
		pause();
	}
	write(1, "\n", 1);
	return (0);
}
