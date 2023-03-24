/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:41:33 by mjina             #+#    #+#             */
/*   Updated: 2023/02/16 13:41:34 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(va_list arg)
{
	ft_putchar_fd(va_arg(arg, int), 1);
	return (1);
}

int	printstring(va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	hexlen(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

int	printhex(va_list arg, char format)
{
	char			str[9];
	int				len;
	unsigned int	nbr;
	int				i;

	nbr = va_arg(arg, unsigned int);
	len = hexlen(nbr);
	i = len;
	if (nbr == 0)
		i = ft_printf("%c", '0');
	while (len > 0)
	{
		if (nbr % 16 <= 9)
			str[--len] = nbr % 16 + '0';
		else if (format == 'x')
			str[--len] = nbr % 16 - 10 + 'a';
		else if (format == 'X')
			str[--len] = nbr % 16 - 10 + 'A';
		nbr /= 16;
	}
	ft_putstr_fd(str, 1);
	return (i);
}
