/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:50:30 by ansilva-          #+#    #+#             */
/*   Updated: 2022/03/10 10:08:48 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_put_base_pointer(unsigned long address, char *base)
{
	int				len;
	unsigned long	n;
	char			*s;
	size_t			len_base;

	len = 0;
	n = address;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	s = malloc(sizeof(*s) * len + 1);
	if (s == NULL)
		return (NULL);
	len_base = ft_strlen(base);
	s[len] = '\0';
	len--;
	while (address > 0)
	{
		s[len] = base[address % len_base];
		address /= len_base;
		len--;
	}
	return (s);
}
