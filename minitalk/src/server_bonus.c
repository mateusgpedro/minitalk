/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:08:19 by maguimar          #+#    #+#             */
/*   Updated: 2023/01/12 17:17:21 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"
#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void	sighandler(int num)
{

}

int	main(int argc, char **argv)
{
	(void) argv;

	if(argc != 1)
	{
		ft_printf("Please, verify the input\n");
		return (0);
	}

	struct sigaction	sa;
	sa.sa_handler = &sighandler;

	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

}
