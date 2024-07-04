/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:26 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/04 19:15:54 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_ptr(char *s, int *count)
{
	int	i;

	i = 0;
	while (s[i])
	{
		*count += write (1, &s[i], 1);
		i++;
	}
}
/*
int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	ft_putstr_fd(argv[2], atoi(argv[1]));
	return (0);
}*/

/*
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
*/
