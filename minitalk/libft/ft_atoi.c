/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:59:23 by ansilva-          #+#    #+#             */
/*   Updated: 2022/03/03 10:25:20 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c == ' ') || (c == '\n') || (c == '\t')
		|| (c == '\v') || (c == '\f') || (c == '\r'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				nb;
	unsigned char	*s;
	int				i;
	int				minus;

	s = (unsigned char *)str;
	minus = 1;
	nb = 0;
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		nb = nb * 10;
		nb = nb + (str[i] - 48);
		i++;
	}
	return (nb * minus);
}
