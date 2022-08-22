/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:46:33 by ansilva-          #+#    #+#             */
/*   Updated: 2022/06/09 14:26:45 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, unsigned char *message)
{
	int		index;
	int		bit;

	index = 0;
	while (message[index])
	{
		bit = 128;
		while (bit > 0)
		{
			if ((message[index] & bit) == bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit /= 2;
			usleep(120);
		}
		index++;
		usleep(200);
	}
}

void	handler(int signo)
{
	static int	signal;

	if (signo != SIGUSR1 || signal == 1)
		return ;
	signal = 1;
	ft_printf("Message successfully received!\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	action_client;

	if (argc != 3)
	{
		ft_printf("Invalid arguments!\n");
		ft_printf("Expected: ./client [server PID] [message]\n");
		return (0);
	}
	sigemptyset(&action_client.sa_mask);
	action_client.sa_handler = &handler;
	if (sigaction(SIGUSR1, &action_client, NULL) == -1)
	{
		ft_printf("sigaction failed!\n");
		return (0);
	}
	send_message(ft_atoi(argv[1]), (unsigned char *)argv[2]);
	return (0);
}
