/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:42:24 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/05 20:58:18 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_args_selector(va_list arguments, char c, int *countaddr)
{
	if (c == 'c')
		ft_putchar_ptr(va_arg(arguments, int), countaddr);
	else if (c == 's')
		ft_putstr_ptr(va_arg(arguments, char *), countaddr);
	else if (c == 'p')
		ft_printptr((uintptr_t)va_arg(arguments, void *), countaddr);
	else if (c == 'd' || c == 'i')
		ft_putnbr_ptr(va_arg(arguments, int), countaddr);
	else if (c == 'u')
		ft_unsigned_putnbr_ptr(va_arg(arguments, unsigned long long), countaddr);
	else if (c == 'x' || c == 'X')
		ft_putnbr_hex_ptr(va_arg(arguments, unsigned long long), countaddr, c);
	else
		*countaddr += write (1, "%", 1);
}
