/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:40:34 by ansilva-          #+#    #+#             */
/*   Updated: 2022/03/03 10:43:28 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	b;

	b = c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == b)
			return ((char *)s + len);
		len--;
	}
	return (0);
}
