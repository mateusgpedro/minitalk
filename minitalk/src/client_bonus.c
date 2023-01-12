/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:08:22 by maguimar          #+#    #+#             */
/*   Updated: 2023/01/12 18:50:08 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"
#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void	send_msg_to_server(int server_pid, char message_to_send)
{
	int bits;

	bits = 0;
	while (bits <= 7)
	{
		if ((message_to_send >> bits) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(150);
		bits++;
	}
}

void	client_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void) sig;
	(void) info;
	(void) ucontext;
	ft_printf("Message received!");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_client;
	int	server_pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("Please, verify the input: <./client> <PID> <message>");
		return(0);
	}
	sa_client.sa_flags = SA_SIGINFO;
	sa_client.sa_sigaction = &client_handler;
	sigemptyset(&sa_client.sa_mask);
	i = 0;
	server_pid = ft_atoi(argv[1]);
	if (sigaction(SIGUSR1, &sa_client, NULL) == -1)
		ft_printf("Failed to receive signal");
	while (argv[2][i])
	{
		send_msg_to_server(server_pid, argv[2][i]);
		i++;
	}
	send_msg_to_server(server_pid, '\n');
	send_msg_to_server(server_pid, '\0');
}
