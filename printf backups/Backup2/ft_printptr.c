/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:11:59 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/05 17:43:54 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printptr(uintptr_t addr, int *count)
{
	if (addr != 0)
	{
		ft_putstr_ptr("0x", count);
		ft_putnbr_hex_ptr(addr, count, 'x');
	}
	else
		ft_putstr_ptr("(nil)", count);
}
