/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:46:20 by ansilva-          #+#    #+#             */
/*   Updated: 2022/06/09 14:05:39 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	conversion_to_decimal(char *binary_message, int pid)
{
	int		bit;
	int		index;
	int		message_decimal;

	message_decimal = 0;
	index = 0;
	bit = 128;
	while (bit > 0)
	{
		if (binary_message[index] == '1')
			message_decimal += bit;
		index++;
		bit /= 2;
	}
	ft_printf("%c", message_decimal);
	kill(pid, SIGUSR1);
}

void	receive_message(int signo, siginfo_t *info, void *nothing)
{
	static char	byte_of_message[8];
	static int	index;
	pid_t		pid;

	(void)nothing;
	pid = info->si_pid;
	if (signo == SIGUSR1)
		byte_of_message[index] = '1';
	else if (signo == SIGUSR2)
		byte_of_message[index] = '0';
	index++;
	if (index == 8)
	{
		conversion_to_decimal(byte_of_message, pid);
		index = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action_server;
	sigset_t			block_signal;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sigemptyset(&block_signal);
	sigaddset(&block_signal, SIGUSR1);
	sigaddset(&block_signal, SIGUSR2);
	action_server.sa_mask = block_signal;
	action_server.sa_sigaction = &receive_message;
	action_server.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action_server, NULL);
	sigaction(SIGUSR2, &action_server, NULL);
	while (1)
		pause();
	return (0);
}
