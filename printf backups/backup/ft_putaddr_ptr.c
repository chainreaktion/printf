/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:44:47 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/05 14:13:54 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putaddr_ptr(unsigned long int addr, int *count, va_list *arguments)
{
	if (addr == 0)
		ft_putstr_ptr("(nil)", count);
	else
	{
		ft_putstr_ptr("0x", count);
		ft_putnbr_hex_ptr((unsigned long int)va_arg(*arguments, void *), count, 'x');
	}
}
