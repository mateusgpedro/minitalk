/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:50:25 by maguimar          #+#    #+#             */
/*   Updated: 2022/12/06 14:52:07 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_hexa(char c, unsigned long nb)
{
	int		count;
	char	*base;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (nb < 16)
		count += ft_printfc(*(base + nb));
	else if (nb >= 16)
	{
		count += ft_printf_hexa(c, nb / 16);
		count += ft_printf_hexa(c, nb % 16);
	}
	return (count);
}
