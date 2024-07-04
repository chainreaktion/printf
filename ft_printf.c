/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:51:24 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/04 19:50:47 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar_ptr(char c, int *count);
void	ft_putnbr_hex_ptr(long long int nbr, int *count, char	casetype);
void	ft_putnbr_ptr(int n, int *count);
void	ft_putstr_ptr(char *s, int *count);
size_t	ft_strlen(const char *s);


int	ft_printf(const char *format, ...)
{
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
			{
				count += write(2, "0x", 2);
				ft_putnbr_hex_ptr((long long int)va_arg(arguments, void *), &count, 'x');
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				ft_putnbr_ptr(va_arg(arguments, int), &count);
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

	/*char	*str = "Dies ist ein Test-String";
	char	c = 'o';
	int		ret;
	int	Zahl = 99;
	int Zahl1 = 45738472;

	ret = ft_printf("String (s): %s\t", str);
	printf("%d\n", ret);
	ret = printf("String (s): %s\t", str);
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
}*/
