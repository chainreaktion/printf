/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:51:24 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/07 20:48:11 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
if (!format)
	return (-1);
va_list	arguments;
int		count;
int		i;
va_start	(arguments, format);
count = 0;
i = 0;
while (format[i] != '\0')
{
	if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				ft_putchar_ptr(va_arg(arguments, int), &count);
			else if (format[i + 1] == 's')
				ft_putstr_ptr(va_arg(arguments, char *), &count);
			else if (format[i + 1] == 'p')
				ft_putaddr_ptr((unsigned long int)va_arg(arguments, void *), &count, &arguments);
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				ft_putnbr_ptr(va_arg(arguments, int), &count);
			else if (format[i + 1] == 'u')
				ft_unsigned_putnbr_ptr(va_arg(arguments, unsigned long), &count);
			else if (format[i + 1] == 'x' || format[i + 1] == 'X')
				ft_putnbr_hex_ptr(va_arg(arguments, int), &count, format[i + 1]);
			else if (format[i + 1] == '%')
				count += write (1, "%", 1);
			i += 2;
		}
	else
	{
		ft_putchar_ptr(format[i], &count);
		i++;
	}
}
va_end (arguments);
return (count);
}
/*
#include <stdio.h>

int main()
{
	char	*str = "Dies ist ein Test-String";
	char 	*empty = "\0";
	char	*nothing = NULL;
	char	c = 'o';
	int		ret;
	int	Zahl = 99;
	int Zahl1 = 45738472;

	ret = ft_printf("String (s): %s\t", str);
	printf("%d\n", ret);
	ret = printf("String (s): %s\t", str);
	printf("%d\n", ret);

	ret = ft_printf("Empty string (s): %s\t", empty);
	printf("%d\n", ret);
	ret = printf("Empty string (s): %s\t", empty);
	printf("%d\n", ret);

	ret = ft_printf("Nullstring (s): %s\t", nothing);
	printf("%d\n", ret);
	ret = printf("Nullstring (s): %s\t", nothing);
	printf("%d\n", ret);

	ret = ft_printf("'o' (c): %c\t", c);
	printf("%d\n", ret);
	ret = printf("'o' (c): %c\t", c);
	printf("%d\n", ret);

	ret = ft_printf("Prozent: %%\t");
	printf("%d\n", ret);
	ret = printf("Prozent: %%\t");
	printf("%d\n", ret);

	ret = ft_printf("Stringadresse (p): %p\t", str);
	printf("%d\n", ret);
	ret = printf("Stringadresse (p): %p\t", str);
	printf("%d\n", ret);

	ret = ft_printf("Intadresse (p): %p\t", &Zahl);
	printf("%d\n", ret);
	ret = printf("Intadresse (p): %p\t", &Zahl);
	printf("%d\n", ret);

	ret = ft_printf("Integer: %d\t", Zahl);
	printf("%d\n", ret);
	ret = printf("Integer: %d\t", Zahl);
	printf("%d\n", ret);

	ret = ft_printf("Hexamin (x): %x\t", Zahl1);
	printf("%d\n", ret);
	ret = printf("Hexamin (x): %x\t", Zahl1);
	printf("%d\n", ret);

	ret = ft_printf("Hexamaj (X): %X\t", Zahl1);
	printf("%d\n", ret);
	ret = printf("Hexamaj (X): %X\t", Zahl1);
	printf("%d\n", ret);

	return (0);
}
*/
