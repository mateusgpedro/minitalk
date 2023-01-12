/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:57:35 by maguimar          #+#    #+#             */
/*   Updated: 2022/12/06 14:32:59 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_specifier(va_list va, char c)
{
	int	bytes_readen;

	bytes_readen = 0;
	if (c == 'c')
		bytes_readen = ft_printfc(va_arg(va, int));
	else if (c == 's')
		bytes_readen = ft_printfs(va_arg(va, char *));
	else if (c == 'd' || c == 'i')
		bytes_readen = ft_printfd(va_arg(va, int));
	else if (c == 'u')
		bytes_readen = ft_printfu(va_arg(va, unsigned long));
	else if (c == 'x' || c == 'X')
		bytes_readen = ft_printf_hexa(c, va_arg(va, unsigned int));
	else if (c == '%')
		bytes_readen = write(1, "%", 1);
	else if (c == 'p')
		bytes_readen = ft_printfp(va_arg(va, unsigned long));
	return (bytes_readen);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	va;
	int		bytes_readen;

	i = 0;
	bytes_readen = 0;
	va_start(va, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			bytes_readen += check_specifier(va, format[i]);
		}
		else
			bytes_readen += write(1, &format[i], 1);
		i++;
	}
	va_end(va);
	return (bytes_readen);
}

/* int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	char *d = "o";
	// ft_printf("ola, %d", d);
	ft_printf("fjpofoe %s %s %s", d, d, d);
}
 */
