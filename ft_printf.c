/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:43:57 by mjina             #+#    #+#             */
/*   Updated: 2023/02/15 13:43:58 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

static int	checkconversion(char c, va_list argument)
{
	if (c == 'c')
		return (printchar(va_arg(arg, int)));
	else if (c == 's')
		return (printstring(argument));
	else if (c == 'p')
		return (printadress(argument));
	else if (c == 'd')
		return (printint(argument));
	else if (c == 'i')
		return (printint(argument));
	else if (c == 'u')
		return (printuint(argument));
	else if (c == 'x')
		return (printhex(argument, c));
	else if (c == 'X')
		return (printhex(argument, c));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	size_t	i;
	va_list	ap;

	i = 0;
	ret = 0;
	va_start(ap, str);
	while (i < ft_strlen(str))
	{
		if (str[i] == '%')
		{
			ret += checkconversion(str[++i], ap);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			ret++;
			i++;
		}
	}
	va_end(ap);
	return (ret);
}
