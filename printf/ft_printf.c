/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:31:00 by ansilva-          #+#    #+#             */
/*   Updated: 2022/03/10 10:16:56 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(va_list args, char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar((char)va_arg(args, int));
	else if (format == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		i += ft_put_pointer(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		i += ft_put_di(va_arg(args, int));
	else if (format == 'u')
		i += ft_put_u(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		i += ft_put_hex(va_arg(args, int), format);
	else if (format == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		index;

	if (!format)
		return (0);
	va_start(args, format);
	index = 0;
	i = 0;
	while (format[index])
	{
		if (format[index] == '%')
			i += conversion(args, format[++index]);
		else
			i += ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	return (i);
}

// int	main(void)
// {
// 	ft_printf("%50000.+%\n");
// 	ft_printf("--------------------------\n");
// 	printf("% d\n", 42);
// 	return (0);
// }
