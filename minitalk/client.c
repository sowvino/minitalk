/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-08 09:50:07 by selango           #+#    #+#             */
/*   Updated: 2024-08-08 09:50:07 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_bit(int pid, char *str, size_t len)
{
	size_t	i;
	int		shift;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 8)
		{
			if ((str[i] >> shift) & 1)
			{
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
			}
			shift++;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;
	size_t	len;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		len = ft_strlen(argv[2]);
		char_to_bit(pid, str, len);
	}
	else
		ft_printf("Please type Server PID and string");
}
