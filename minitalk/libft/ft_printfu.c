/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:49:23 by maguimar          #+#    #+#             */
/*   Updated: 2022/12/06 16:29:33 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printfu(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb < 10)
	{
		count += ft_printfc(nb + '0');
	}
	else if (nb >= 10)
	{
		count += ft_printfd(nb / 10);
		count += ft_printfd(nb % 10);
	}
	return (count);
}
