/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:00:45 by maguimar          #+#    #+#             */
/*   Updated: 2022/12/05 16:56:57 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_printfc(char str);
int	ft_printfs(char *str);
int	ft_printfd(long nb);
int	ft_printfu(unsigned int nb);
int	ft_printf_hexa(char c, unsigned long nb);
int	ft_printfp(unsigned long nb);

#endif
