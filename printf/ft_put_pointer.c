/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:53:35 by ansilva-          #+#    #+#             */
/*   Updated: 2022/03/07 16:49:05 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_pointer(void *p)
{
	unsigned long	address;
	int				i;
	char			*s;
	char			*base;

	i = 0;
	if (p == NULL)
		i += ft_putstr("(nil)");
	else
	{
		address = (unsigned long)p;
		base = "0123456789abcdef";
		s = ft_put_base_pointer(address, base);
		i += ft_putstr("0x");
		i += ft_putstr(s);
		free (s);
	}
	return (i);
}
