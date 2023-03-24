/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:57:36 by mjina             #+#    #+#             */
/*   Updated: 2023/02/16 14:57:36 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printint(int nbr)
{
	char	*str;
	int		i;

	str = ft_itoa(nbr);
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	free (str);
	return (i);
}

static int	intlen(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	i;
	char			*str;

	i = intlen(n);
	if (n == 0)
		return (str = ft_strdup("0"));
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[intlen(n)] = '\0';
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		str[i - 1] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str);
}

int	printuint(int nbr)
{
	char	*str;
	int		i;

	str = ft_uitoa(nbr);
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	free (str);
	return (i);
}

int	printadress(va_list arg)
{
	unsigned long int	n;
	int					i;

	n = va_arg(arg, unsigned long int);
	if (n == 0)
		return (ft_printf("(nil)"));
	i = ft_printf("0x");
	i = ft_printf("%x", n);
	/*while (len > 0)
	{
		if (nbr % 16 <= 9)
			str[--len] = nbr % 16 + '0';
		else
			str[--len] = nbr % 16 - 10 + 'a';
		nbr /= 16;
	}*/
	return (i);
}
