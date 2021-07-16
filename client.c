/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayqotbi <ayqotbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:32:04 by ayqotbi           #+#    #+#             */
/*   Updated: 2021/06/21 18:32:04 by ayqotbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit_by_bit(int pid, char *msg, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((msg[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(100);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;

	if (ac == 3)
	{
		pid = ft_get_num(av[1]);
		if (!pid)
		{
			ft_putstr_fd("enter a valid pid\n", 1);
			return (0);
		}
		pid = ft_atoi(av[1]);
		send_bit_by_bit(pid, av[2], ft_strlen(av[2]));
	}
	else
		ft_putstr_fd("usage: ./client [server_pid] [msg_to_send]\n", 1);
	return (0);
}
