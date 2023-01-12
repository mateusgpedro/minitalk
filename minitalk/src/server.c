/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:41:13 by maguimar          #+#    #+#             */
/*   Updated: 2023/01/11 15:18:03 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void sighandler(int signum)
{
	static int bits;
	static char final_msg;

	if (signum == SIGUSR1)
		final_msg = ((1 << bits) | final_msg);
	else
		final_msg = ((0 << bits) | final_msg);
	bits++;
	if (bits == 8)
	{
		write(1, &final_msg, 1);
		bits = 0;
		final_msg = '\0';
	}
}

int main(int argc, char **argv)
{
	int	pid;
	(void) argv;

	if (argc != 1)
	{
		ft_printf("Please, verify the input\n");
		return (0);
	}

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, &sighandler);
	signal(SIGUSR2, &sighandler);
	while (1)
		pause();
}
