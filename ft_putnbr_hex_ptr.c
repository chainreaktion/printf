/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:30:23 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/04 19:32:01 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_hex_ptr(long long int nbr, int *count, char	casetype)
{
	//int		i;
	char	*base;

	if (casetype == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	//i = 0;
	{
		/*
		if (nbr == -2147483648)
		{
			ft_putchar_ptr('-', count);
			ft_putnbr_hex_ptr(2147483648 / 16, count, casetype);
			ft_putchar_ptr(2147483648 % 16, count);
		}
		else
		*/
			if (nbr < 0)
			{
				ft_putchar_ptr('-', count);
				nbr = -nbr;
			}

		if (nbr >= 16)
			ft_putnbr_hex_ptr(nbr / 16, count, casetype);
		ft_putchar_ptr(base[nbr % 16], count);
	}
}
/*
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	else
		ft_putnbr_base(atoi(argv[1]), argv[2]);
	return (0);
}*/
/*
   int main()
   {
   int nbr = 42;
   char *base = "01";
   ft_putnbr_base(nbr, base);
   return (0);
   }*/
