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

int	printchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	printstring(char  *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	hexlen(unsigned int nbr)
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

static void fillhex(unsigned int nbr, char *str, int index, char format)
{
	if (nbr >= 16)
		fillhex(nbr / 16, str++, ++index, format);
	if (nbr % 16 <= 9)
		str[index] = nbr % 16 + '0';
	else if (format == 'x')
		str[index] = nbr % 16 - 10 + 'a';
	else if (format == 'X')
		str[index] = nbr % 16 - 10 + 'A';
}

int	printhex(unsigned int nbr, char format)
{
	char	str[8];
	int		len;
	int		i;

	len = hexlen(nbr);
	i = len;
	//if (nbr == 0)
	//	i = ft_printf("%c", '0');
	fillhex(nbr, str, 0, format);
	/*while (len > 0)
	{
		if (nbr % 16 <= 9)
			str[--len] = nbr % 16 + '0';
		else if (format == 'x')
			str[--len] = nbr % 16 - 10 + 'a';
		else if (format == 'X')
			str[--len] = nbr % 16 - 10 + 'A';
		nbr /= 16;
	}*/
	ft_putstr_fd(str, 1);
	return (i);
}
