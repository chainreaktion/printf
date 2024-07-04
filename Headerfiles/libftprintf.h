/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:39:06 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/04 19:33:22 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_ptr(char c, int *count);
void	ft_putnbr_hex_ptr(long long int nbr, int *count, char	casetype);
void	ft_putnbr_ptr(int n, int *count);
void	ft_putstr_ptr(char *s, int *count);

#endif
