/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:47:48 by maguimar          #+#    #+#             */
/*   Updated: 2023/01/11 15:14:54 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void	convert_signal_to_bytes(int server_pid, char client_msg)
{
	int bits;

	bits = 0;
	while (bits <= 7)
	{
		if ((client_msg >> bits) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(150);
		bits++;
	}
}

int	main(int argc, char **argv)
{
	(void) argv;
	int server_pid;
	int i;

	if (argc != 3)
	{
		ft_printf("Please, verify the input: <./client> <PID> <message>");
		return(0);
	}
	i = 0;
	server_pid = ft_atoi(argv[1]);
	while(argv[2][i])
	{
		convert_signal_to_bytes(server_pid, argv[2][i]);
		i++;
	}
	convert_signal_to_bytes(server_pid, '\n');
}
