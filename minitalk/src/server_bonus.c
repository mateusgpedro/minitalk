/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:08:19 by maguimar          #+#    #+#             */
/*   Updated: 2023/01/12 18:55:23 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"
#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void	sighandler(int sig, siginfo_t *info, void *ucontext)
{
	static int bits;
	static char final_msg;

	(void) *ucontext;
	if (sig == SIGUSR1)
		final_msg = ((1 << bits) | final_msg);
	else
		final_msg = ((0 << bits) | final_msg);
	bits++;
	if (bits == 8)
	{
		write(1, &final_msg, 1);
		if (final_msg == '\0')
			kill(info->si_pid, SIGUSR1);
		bits = 0;
		final_msg = '\0';
	}
}

int	main(int argc, char **argv)
{
	(void) argv;
	struct sigaction	sa_server;
	int	pid;

	if(argc != 1)
	{
		ft_printf("Please, verify the input\n");
		return (0);
	}
	sa_server.sa_sigaction = &sighandler;
	sa_server.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_server.sa_mask);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &sa_server, NULL);
	sigaction(SIGUSR2, &sa_server, NULL);
	if (sigaction(SIGUSR1, &sa_server, NULL) == -1
		|| sigaction(SIGUSR2, &sa_server, NULL) == -1)
		ft_printf("Failed to receive signal");
	while (1)
		pause();
}
