/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:30:23 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/05 18:22:50 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_hex_ptr(unsigned long long nbr, int *count, char casetype)
{
	char	*base;

	if (casetype == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr >= 16)
		ft_putnbr_hex_ptr(nbr / 16, count, casetype);
	ft_putchar_ptr(base[nbr % 16], count);
}
