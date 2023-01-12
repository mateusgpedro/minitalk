/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:45:12 by maguimar          #+#    #+#             */
/*   Updated: 2022/12/06 15:12:34 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printfp(unsigned long nb)
{
	int	count;

	if (!nb)
		return (write(1, "(nil)", 5));
	write (1, "0x", 2);
	count = ft_printf_hexa('x', nb);
	return (count + 2);
}
